#ifndef GROUP
#define GROUP

#include <vector>
#include "shape.hpp"

namespace ilrd
{
    class Group : public Shape
    {
    public:
        explicit Group();
        virtual ~Group();
        void AddShape(Shape *shape);
        virtual void Draw() const;
        virtual Shape& Move(Point moveToPoint);
        virtual Shape& Move(double xNewLocation, double yNewLocation);
        virtual Shape& Revolve(Point point, double angle);
        virtual Shape& Rotate(double angle);
        virtual void SetColor(COLORS color);
        
    private:
        Point CalculateCenter();
        std::vector<Shape *> m_shapes;
    };
        
}// namespace ilrd

#endif // GROUP