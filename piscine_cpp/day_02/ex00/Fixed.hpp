#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

public:

	Fixed(void);
	Fixed(const int);
	Fixed(Fixed const &);
	~Fixed(void);

	Fixed &				operator=(Fixed const &);

	int					getRawBits(void) const;
	void 				setRawBits(int const);

private:
	int					_n;
	static int const	_fractionnalBits;

};

#endif
