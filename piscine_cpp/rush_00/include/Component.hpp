#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class	Component
{

public:

	enum	Type
	{
		Render = 0,		// keep first initialized to zero for proper count
		Player,
		Enemy,
		Move,
		CollisionBox,
		COUNT				// keep it last
	};

	virtual ~Component();

	Type	getType() const;

protected:

	Component(Type);

private:

	Component();
	Component(const Component&);
	Component&	operator=(const Component&);

	Type	m_type;

	char _pad[4];
};

#endif
