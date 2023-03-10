#ifndef FT_VECTOR
#define FT_VECTOR

#include <memory>

namespace ft
{
	template<typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		/**
		 * Member type
		 */

		typedef T							value_type;
		typedef Allocator					allocator_type;
		typedef std::size_t					size_type;
		typedef std::ptrdiff_t				difference_type;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;
		typedef Allocator::pointer			pointer;
		typedef Allocator::const_pointer	const_pointer;
		/**
		 * iterator 
		 * const_iterator
		 * reverse_iterator
		 * const_reverse_iterator
		 */

		/**
		 * Member functions
		 */
		vector(); // default constructor
		explicit vector( const Allocator& alloc ); // Constructs an empty container witth the given allocator alloc.
		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()); // Constructs the container with count copies of elements with value value.
		template< typename InputIt >
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ); // Constructs the container with the contents of the range [first, last)
		vector(const vector& other); // copy constructor

		~vector();

		vector&	operator=(const vector& rhs);
		void	assign(size_type count, const T& value);
		template<typename InputIt>
		void	assign(InputIt first, InputIt last);
		allocator_type	get_allocator() const;

		/**
		 * Element access
		 */

		reference at(size_type pos);
		const_reference	at(size_type pos) const;
		reference	operator[](size_type pos);
		const_reference	operator[](size_type pos) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		T* data();
		const T* data() const;

		/**
		 * Iterator
		 */
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		/**
		 * Capacity
		 */
		bool empty() const;
		size_type size() const;
		size_type max_size() const;
		void reserve( size_type new_cap );
		size_type capacity() const;

		/**
		 * Modifiers
		 */
		void clear();
		iterator insert( const_iterator pos, const T& value );
		iterator insert( const_iterator pos, size_type count, const T& value );
		template< class InputIt >
		iterator insert( const_iterator pos, InputIt first, InputIt last );
		iterator erase( iterator pos );
		iterator erase( iterator first, iterator last );
		void push_back( const T& value );
		void pop_back();
		void resize( size_type count, T value = T() );
		void swap( vector& other );

	}; // class vector

	/**
	 * Member functions
	 */
	template<typename T, typename Alloc>
	vector<T, Alloc>::vector()
	{
		
	}

	//vector(); // default constructor
	//explicit vector( const Allocator& alloc ); // Constructs an empty container witth the given allocator alloc.
	//explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()); // Constructs the container with count copies of elements with value value.
	//template< typename InputIt >
	//vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ); // Constructs the container with the contents of the range [first, last)
	//vector(const vector& other); // copy constructor

	//~vector();

	//vector&	operator=(const vector& rhs);
	//void	assign(size_type count, const T& value);
	//template<typename InputIt>
	//void	assign(InputIt first, InputIt last);
	//allocator_type	get_allocator() const;

	/**
	 * Non-member functions
	 */
	template<typename T, typename Alloc>
	bool	operator==(const std::vector<T, Alloc>& lhs, const std::vector<T, Alloc>&rhs);
	template<typename T, typename Alloc>
	bool	operator!=(const std::vector<T, Alloc>& lhs, const std::vector<T, Alloc>&rhs);
	template<typename T, typename Alloc>
	bool	operator<(const std::vector<T, Alloc>& lhs, const std::vector<T, Alloc>&rhs);
	template<typename T, typename Alloc>
	bool	operator<=(const std::vector<T, Alloc>& lhs, const std::vector<T, Alloc>&rhs);
	template<typename T, typename Alloc>
	bool	operator>(const std::vector<T, Alloc>& lhs, const std::vector<T, Alloc>&rhs);
	template<typename T, typename Alloc>
	bool	operator>=(const std::vector<T, Alloc>& lhs, const std::vector<T, Alloc>&rhs);
	
} // namespace ft

#endif
