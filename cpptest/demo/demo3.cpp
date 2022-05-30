// clang-format off
#Only two levels are needed:

	template void foo(T)
	requires A || (B && (C || D));

	template void foo(T)
	requires A || ((B && C) || (B && D));

	template<class T> void foo(T)
	requires A<T> || (B<T> && (C<T> || D<T>));

	template<class T> void foo(T)
    requires A<T> || (B<T> && C<T>) || (B<T> && D<T>);
// clang-format on