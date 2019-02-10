#pragma once

#include <memory>

/*
template<class T, class Allocator = allocator<T>>
class Vector
{
public:
typedef T											value_type;
typedef Allocator									allocator_type;
typedef typename allocator::reference				reference;
typedef typename allocator::const_reference			const_reference;
typedef implementation-defined						iterator;
typedef implementation-defined						const_iterator;
typedef typename allocator_type::size_type			size_type;
typedef typename allocator_type::difference_type	difference_type;
typedef typename allocator_type::pointer			pointer;
typedef typename allocator_type::const_pointer		const_pointer;
typedef std::reverse_iterator<iterator>				reverse_iterator;
typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

vector()
noexcept( is_nothrow_default_constructible<allocator_type>::value );
explicit vector( const allocator_type& );
explicit vector( size_type n );
explicit vector( size_type n, const allocator_type& ); // C++14
vector( size_type n, const value_type& value, const allocator_type& = allocator_type() );
template <class InputIterator>
vector( InputIterator first, InputIterator last, const allocator_type& = allocator_type() );
vector( const vector& x );
vector( vector&& x )
noexcept( is_nothrow_move_constructible<allocator_type>::value );
vector( initializer_list<value_type> il );
vector( initializer_list<value_type> il, const allocator_type& a );

~vector();

vector& operator=( const vector& x );
vector& operator=( vector&& x )
noexcept(
allocator_type::propagate_on_container_move_assignment::value ||
allocator_type::is_always_equal::value ); // C++17

vector& operator=( initializer_list<value_type> il );
template <class InputIterator>
void assign( InputIterator first, InputIterator last );
void assign( size_type n, const value_type& u );
void assign( initializer_list<value_type> il );

allocator_type get_allocator( void ) const noexcept;

iterator               begin( void ) noexcept;
const_iterator         begin( void )   const noexcept;
iterator               end( void ) noexcept;
const_iterator         end( void )     const noexcept;

reverse_iterator       rbegin( void ) noexcept;
const_reverse_iterator rbegin( void )  const noexcept;
reverse_iterator       rend( void ) noexcept;
const_reverse_iterator rend( void )    const noexcept;

const_iterator         cbegin( void )  const noexcept;
const_iterator         cend( void )    const noexcept;
const_reverse_iterator crbegin( void ) const noexcept;
const_reverse_iterator crend( void )   const noexcept;

size_type size( void ) const noexcept;
size_type max_size( void ) const noexcept;
size_type capacity( void ) const noexcept;

bool empty( void ) const noexcept;

void reserve( size_type n );
void shrink_to_fit() noexcept;

reference       operator[]( size_type n );
const_reference operator[]( size_type n ) const;
reference       at( size_type n );
const_reference at( size_type n ) const;

reference       front( void );
const_reference front( void ) const;
reference       back( void );
const_reference back( void ) const;

value_type*       data( void ) noexcept;
const value_type* data( void ) const noexcept;

void push_back( const value_type& x );
void push_back( value_type&& x );

template <class... Args>
reference emplace_back( Args&&... args ); // reference in C++17
void pop_back( void );

template <class... Args> iterator emplace( const_iterator position, Args&&... args );
iterator insert( const_iterator position, const value_type& x );
iterator insert( const_iterator position, value_type&& x );
iterator insert( const_iterator position, size_type n, const value_type& x );
template <class InputIterator>
iterator insert( const_iterator position, InputIterator first, InputIterator last );
iterator insert( const_iterator position, initializer_list<value_type> il );

iterator erase( const_iterator position );
iterator erase( const_iterator first, const_iterator last );

void clear( void ) noexcept;
void resize( size_type sz );
void resize( size_type sz, const value_type& c );

void swap(vector&)
noexcept( allocator_traits<allocator_type>::propagate_on_container_swap::value ||
allocator_traits<allocator_type>::is_always_equal::value );  // C++17

bool __invariants( void ) const;
};
*/


namespace prac
{
	template <class _Tp, class _Allocator>
	class __vector_base
	{
	public:
		typedef _Allocator                               allocator_type;
		typedef allocator_traits<allocator_type>         __alloc_traits;
		typedef typename __alloc_traits::size_type       size_type;

	protected:
		typedef _Tp                                      value_type;
		typedef value_type&                              reference;
		typedef const value_type&                        const_reference;
		typedef typename __alloc_traits::difference_type difference_type;
		typedef typename __alloc_traits::pointer         pointer;
		typedef typename __alloc_traits::const_pointer   const_pointer;
		typedef pointer                                  iterator;
		typedef const_pointer                            const_iterator;

		pointer                                         __begin_;
		pointer                                         __end_;
		__compressed_pair<pointer, allocator_type>		__end_cap_;

		allocator_type& __alloc() noexcept
		{
			return __end_cap_.second();
		}

		const allocator_type& __alloc() const noexcept
		{
			return __end_cap.second();
		}



	};
}