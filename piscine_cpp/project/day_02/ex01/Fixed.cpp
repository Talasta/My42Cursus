#include "Fixed.hpp"

Fixed::Fixed(void) : _n(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->_n = std::roundf((float)n * (1 << Fixed::_fractionnalBits));
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	this->_n = std::roundf(n * (1 << Fixed::_fractionnalBits));
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &		Fixed::operator=(Fixed const & src) {
	std::cout << "Assignation operator called" << std::endl;
	this->_n = src.getRawBits();

	return *this;
}

int			Fixed::getRawBits(void) const {
	return this->_n;
}

void 		Fixed::setRawBits(int const raw) {
	this->_n = raw;
}

float 		Fixed::toFloat(void) const {
	float	res = (float)(this->getRawBits()) / (1 << Fixed::_fractionnalBits);
	return res;
}

int 		Fixed::toInt(void) const {
	int		res = std::roundf((float)(this->getRawBits()) / (1 << Fixed::_fractionnalBits));
	return res;
}

std::ostream &			operator<<(std::ostream & o , Fixed const & rf) {
	o << rf.toFloat();
	return o;
}


const int	Fixed::_fractionnalBits = 8;
