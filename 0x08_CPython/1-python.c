#include <Python.h>

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
