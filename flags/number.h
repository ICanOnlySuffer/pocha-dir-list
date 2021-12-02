
if ('0' <= *args [i] && *args [i] <= '9') {
	number_buffer [number_buffer_index++] = *args [i];
} else {
	number_buffer_index = 0;
	*number = atoi (number_buffer);
	printf ("%i\n", delay);
}









