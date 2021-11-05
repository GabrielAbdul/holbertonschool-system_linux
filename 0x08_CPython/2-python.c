#include <Python.h>

/**
 * print_python_bytes - prints basic info about bython bytes
 * @p: Python object
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i, num_bytes;
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
	size = PyBytes_Size(p);
	bytes_as_string = PyBytes_AsString(p);
	num_bytes = size > 9 ? 10 : size + 1;
	/* printing info */
	printf("size: %li\n  ", size);
	printf("trying string: %s\n  ", bytes_as_string);
	printf("first %ld bytes", num_bytes);


	for (i = 0; i < size - 1 && i < 10; i++)
		printf(" %02x", bytes_as_string[i]);
	putchar('\n');
}

/**
 * print_python_list - description
 * @p: python object pointer
 */
void print_python_list(PyObject *p)
{
	ssize_t i;

	/* prints basic info about a python list */
	printf("[*] Python list info\n"
		   "[*] Size of the Python List = %li\n"
		   "[*] Allocated = %li\n",
		   PyList_Size(p), ((PyListObject *) p)->allocated);

	/* print some basic info about each element of the input list p */
	for (i = 0; i < Py_SIZE(p); i++)
		printf("Element %li: %s\n", i, Py_TYPE((PyList_GetItem(p, i)))->tp_name);
}
