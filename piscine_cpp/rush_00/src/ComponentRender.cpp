#include <ComponentRender.hpp>

ComponentRender::ComponentRender(const char* c, Layer layer) : Component(s_type), m_repr(c), m_layer(layer)
{
}

ComponentRender::~ComponentRender()
{
}

ComponentRender::Layer  ComponentRender::getLayer() const
{
    return m_layer;
}

void                    ComponentRender::setLayer(Layer layer)
{
	m_layer = layer;
}

const char*             ComponentRender::getRepr() const
{
    return m_repr.c_str();
}

void	ComponentRender::setRepr(const char* repr)
{
	m_repr = repr;
}
