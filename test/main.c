extern void main_test_util_makros(void);
extern void main_test_result(void);
extern void main_test_string_view(void);

int main(void)
{
	main_test_util_makros();
	main_test_result();
	main_test_string_view();

	return 0;
}
