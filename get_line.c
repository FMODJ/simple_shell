#include "shell.h"

/**
 * main; entry point
 * input_buf - buffers chained commands
 * @buf: buffer address
 * @len: address of the len variable
 * Return: 0 when successful, -1 on error
 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
