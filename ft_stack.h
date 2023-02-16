#ifndef FT_STACK_H
#define FT_STACK_H

// Replace std::vector to ft::vector
#include <vector>

namespace ft
{
	template <typename T, typename Container = std::vector<T> >
	class stack
	{
	public:
		typedef	Container							container_type;
		typedef	typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

	protected:
		container_type	c;

	public:
		/**
		 * Member functions
		 */
		explicit stack(const Container& cont = Container()) //This is also the default constructor. (until C++11)
			: c(cont)
		{
		}
		virtual ~stack()
		{
		}
		stack&	operator=(const stack& rhs)
		{
			if (*this == rhs)
				return *this;

			c = rhs.c;
			return *this;
		}

		/**
		 * Element access
		 */
		reference	top();// Calling back on an empty container causes undefined behavior.
		const_reference	top() const;

		/**
		 * Capacity
		 */
		bool	empty() const;
		size_type	size() const;

		/**
		 * Modifiers
		 */
		void	push(const value_type& value);
		void	pop();
	}; // class stack

	/**
	 * stack
	*/
	template<typename T, typename Container>
	typename stack<T, Container>::reference
	stack<T, Container>::top()
	{
		return c.back(); // Calling back on an empty container causes undefined behavior.
	}

	template<typename T, typename Container>
	typename stack<T, Container>::const_reference
	stack<T, Container>::top() const
	{
		return c.back();
	}

	template<typename T, typename Container>
	bool	stack<T, Container>::empty() const
	{
		return c.empty();
	}

	template<typename T, typename Container>
	typename stack<T, Container>::size_type
	stack<T, Container>::size() const
	{
		return c.size();
	}

	template<typename T, typename Container>
	void	stack<T, Container>::push(const value_type& value)
	{
		c.push_back(value);
	}

	template<typename T, typename Container>
	void	stack<T, Container>::pop()
	{
		c.pop_back();
	}

	/**
	 * Non-member functions
	 */

	template<typename T, typename Container>
	bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return lhs.c == rhs.c;
	}

	template<typename T, typename Container>
	bool	operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return !(lhs.c == rhs.c);
	}

	template<typename T, typename Container>
	bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template<typename T, typename Container>
	bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return !(rhs.c < lhs.c);
	}

	template<typename T, typename Container>
	bool	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return (rhs.c < lhs.c);
	}

	template<typename T, typename Container>
	bool	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
		return !(lhs.c < rhs.c);
	}

}	// namespace ft

#endif	// header include guard
