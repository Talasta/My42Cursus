#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

public:

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

private:
	int					_n;
	static int const	_fractionnalBits;

};

std::ostream &			operator<<(std::ostream &, Fixed const &);

#endif
