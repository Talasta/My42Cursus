#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

public:

	static Fixed const & 	min(Fixed const &, Fixed const &);
	static Fixed const & 	max(Fixed const &, Fixed const &);
	static Fixed  & 	min(Fixed  &, Fixed  &);
	static Fixed  & 	max(Fixed  &, Fixed  &);

	Fixed(void);
	Fixed(float const);
	Fixed(int const);
	Fixed(Fixed const &);
	~Fixed(void);

	Fixed &				operator=(Fixed const &);

	int					getRawBits(void) const;
	void 				setRawBits(int const);

	float 				toFloat(void) const;
	int 				toInt(void) const;

	Fixed 				operator+(Fixed const &);
	Fixed 				operator-(Fixed const &);
	Fixed 				operator*(Fixed const &);
	Fixed 				operator/(Fixed const &);

	bool				operator>(Fixed const &) const ;
	bool				operator<(Fixed const &) const ;
	bool				operator>=(Fixed const &) const ;
	bool				operator<=(Fixed const &) const ;
	bool				operator==(Fixed const &) const ;
	bool				operator!=(Fixed const &) const ;

	Fixed 				operator++(int);
	Fixed 				operator--(int);
	Fixed 				operator++();
	Fixed 				operator--();

private:
	int					_n;
	static int const	_fractionnalBits;
	static float const	_eps;

};

std::ostream &			operator<<(std::ostream &, Fixed const &);

#endif
