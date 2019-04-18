#ifndef LINE
#define LINE

#include "shape.hpp"

namespace ilrd
{
    class Line : public Shape
    {
    public:
        Line(Point point, COLORS color, double angle,  
                double length);
        virtual ~Line();
        void SetLength(double length);
        double GetLength() const;
        virtual void Draw() const;
        
    private:
        double m_length;
    };
        
}// namespace ilrd

#endif // LINE