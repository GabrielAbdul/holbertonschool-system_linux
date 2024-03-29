#include <Python.h>

/**
 * print_python_float - prints python float values
 * @p: Python object
 */
void print_python_float(PyObject *p)
{
	double dub;
	char *s;

	printf("[.] float object info\n");

	if (!p || !PyFloat_Check(p))
	{
		printf("%2s", "[ERROR] Invalid Float Object\n");
		return;
	}

	dub = (((PyFloatObject *)(p))->ob_fval);
	s = PyOS_double_to_string(dub, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
	printf("  value: %s\n", s);
}

/**
 * print_python_bytes - prints basic info about bython bytes
 * @p: Python object
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, num_bytes, i;
	char *bytes_as_string;

	/* printing detailing description */
	printf("[.] bytes object info\n  ");

	/* check if valid bytes object */
	if (!PyBytes_Check(p))
	{
		printf("%2s", "[ERROR] Invalid Bytes Object\n");
		return;
	}

	/* extracting information from python object */
	size = ((PyVarObject *)(p))->ob_size;
	bytes_as_string = ((PyBytesObject *)(p))->ob_sval;
	num_bytes = size > 9 ? 10 : size + 1;

	/* printing info */
	printf("size: %li\n  ", size);
	printf("trying string: %s\n  ", bytes_as_string);
	printf("first %ld bytes:", num_bytes);


	for (i = 0; i < num_bytes; i++)
		printf(" %02hhx", bytes_as_string[i]);
	putchar('\n');
}

/**
 * print_python_list - description
 * @p: python object pointer
 */
void print_python_list(PyObject *p)
{
	ssize_t i;
	PyObject *obj;

	/* check if valid list obj, otherwise segfault */
	if (p->ob_type != &PyList_Type)
	{
		printf("%2s", "[ERROR] Invalid List Object\n");
		return;
	}
	/* prints basic info about a python list */
	printf("[*] Python list info\n"
		   "[*] Size of the Python List = %li\n"
		   "[*] Allocated = %li\n",
		   ((PyVarObject *)p)->ob_size, ((PyListObject *) p)->allocated);

	/* print some basic info about each element of the input list p */
	for (i = 0; i < ((PyVarObject *)p)->ob_size; i++)
	{
		obj = ((PyListObject *)(p))->ob_item[i];
		printf("Element %li: %s\n", i, obj->ob_type->tp_name);
		if (PyBytes_Check(obj))
			print_python_bytes(obj);
		else if (PyFloat_Check(obj))
			print_python_float(obj);
	}
}
