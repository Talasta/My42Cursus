#include "Fixed.hpp"

Fixed::Fixed(void) : _n(0) {}

Fixed::Fixed(const int n) {
	this->setRawBits(std::roundf((float)n * (1 << Fixed::_fractionnalBits)));
}

Fixed::Fixed(const float n) {
	this->setRawBits(std::roundf(n * (1 << Fixed::_fractionnalBits)));
}

Fixed::~Fixed(void) {}

Fixed::Fixed(Fixed const & src) {
	*this = src;
}

Fixed &		Fixed::operator=(Fixed const & src) {
	this->setRawBits(src.getRawBits());
	return *this;
}

float 		Fixed::toFloat(void) const {
	float	res = (float)(this->getRawBits()) / (1 << Fixed::_fractionnalBits);
	return res;
}

int 		Fixed::toInt(void) const {
	int		res = std::roundf((float)(this->getRawBits()) / (1 << Fixed::_fractionnalBits));
	return res;
}

bool		Fixed::operator>(Fixed const & rf) const {
	return (this->toFloat() > rf.toFloat());
}

bool		Fixed::operator<(Fixed const & rf) const {
	return (this->toFloat() < rf.toFloat());
}

bool		Fixed::operator>=(Fixed const & rf) const {
	return (*this > rf || *this == rf);
}

bool		Fixed::operator<=(Fixed const & rf) const {
	return (*this < rf || *this == rf);
}

bool		Fixed::operator==(Fixed const & rf) const {
	return ((rf.toFloat() + Fixed::_eps) > this->toFloat() && this->toFloat() > (rf.toFloat() - Fixed::_eps));
}

bool		Fixed::operator!=(Fixed const & rf) const {
	return (!(*this == rf));
}

Fixed 		Fixed::operator+(Fixed const & rf) {
	Fixed 	f;
	f.setRawBits(this->getRawBits() + rf.getRawBits());
	return f;
}

Fixed 		Fixed::operator-(Fixed const & rf) {
	Fixed 	f;
	f.setRawBits(this->getRawBits() - rf.getRawBits());
	return f;
}

Fixed 		Fixed::operator*(Fixed const & rf) {
	Fixed 	f;
	f.setRawBits((this->getRawBits() * rf.getRawBits()) >> Fixed::_fractionnalBits);
	return f;
}

Fixed 		Fixed::operator/(Fixed const & rf) {
	Fixed 	f;
	f.setRawBits((this->getRawBits() / rf.getRawBits()) << Fixed::_fractionnalBits);
	return f;
}

Fixed 		Fixed::operator++(int) {
	Fixed	f = Fixed(*this);
	this->setRawBits(this->getRawBits() + 1);
	return f;
}

Fixed 		Fixed::operator--(int) {
	Fixed	f = Fixed(*this);
	this->setRawBits(this->getRawBits() - 1);
	return f;
}

Fixed 		Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed 		Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

std::ostream &			operator<<(std::ostream & o , Fixed const & rf) {
	o << rf.toFloat();
	return o;
}

int			Fixed::getRawBits(void) const { return this->_n; }
void 		Fixed::setRawBits(int const raw) { this->_n = raw; }

Fixed & 	Fixed::min(Fixed & r1, Fixed & r2) {
	if ((r1 > r2) == true) {
		return r2;
	}
	return r1;
}

Fixed & 	Fixed::max(Fixed & r1, Fixed & r2) {
	if ((r1 < r2) == true) {
		return r2;
	}
	return r1;
}

Fixed const & 	Fixed::min(Fixed const & r1, Fixed const & r2) {
	if ((r1 > r2) == true) {
		return r2;
	}
	return r1;
}

Fixed const & 	Fixed::max(Fixed const & r1, Fixed const & r2) {
	if ((r1 < r2) == true) {
		return r2;
	}
	return r1;
}

const int	Fixed::_fractionnalBits = 8;
const float	Fixed::_eps				= 1e-8f;
