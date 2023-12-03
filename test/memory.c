/**
 * clear_buffer - a fuction that clears existing data in allocated buffers.
 *
 * @buffer: char *
 * @size: int
 * Return: void
 */
void clear_buffer(char *buffer, int size)
{
	int i;

	for (i = 0; i < size; ++i)
	{
		buffer[i] = '\0';
	}
}
