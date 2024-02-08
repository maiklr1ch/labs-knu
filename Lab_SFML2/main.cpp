#define _USE_MATH_DEFINES

#include <cmath>
#include <SFML/Graphics.hpp>
#include <stdlib.h>

using namespace sf;
using namespace std;

class EllipseShape : public Shape
{
public:

    EllipseShape(const Vector2f& radius = Vector2f(0, 0), const size_t pointCount = 900)
    {
        m_radius = radius;
        point_count = pointCount;
        update();
    }

    EllipseShape(const float x = 0, const float y = 0, const size_t pointCount = 900)
    {
        m_radius = Vector2f(x, y);
        point_count = pointCount;
        update();
    }

    void setRadius(const Vector2f& radius)
    {
        m_radius = radius;
        update();
    }

    const Vector2f& getRadius() const
    {
        return m_radius;
    }

    virtual size_t getPointCount() const
    {
        return point_count;
    }

    virtual Vector2f getPoint(size_t index) const
    {
        float angle = index * 2 * M_PI / getPointCount() - M_PI / 2;
        float x = cos(angle) * m_radius.x;
        float y = sin(angle) * m_radius.y;

        return Vector2f(m_radius.x + x, m_radius.y + y);
    }

private:

    Vector2f m_radius;
    size_t point_count;
};

const float ellipseA = 150.f, ellipseB = 100.f;
const float resolutionX = 600.f, resolutionY = 400.f;
const float pointRadius = 4.f;
const float speed = 0.1f;

int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(resolutionX, resolutionY), "Lab 2.18", Style::Close);
    EllipseShape ellipse(Vector2f(ellipseA, ellipseB));

    ellipse.setFillColor(Color::Black);
    ellipse.setPosition(resolutionX / 2 - ellipseA, resolutionY / 2 - ellipseB);
    ellipse.setOutlineThickness(pointRadius);
    ellipse.setOutlineColor(Color::Black);

    CircleShape point(pointRadius);
    point.move(resolutionX / 2 - pointRadius, resolutionY / 2 - pointRadius);
    point.setFillColor(Color::Red);

    Vector2f moveFactor(((rand() % 2) ? 1 : -1) * speed, ((rand() % 2) ? 1 : -1) * speed);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        float x = pointRadius + point.getPosition().x - resolutionX / 2;
        float y = pointRadius + point.getPosition().y - resolutionY / 2;
        if ((x * x) / (ellipseA * ellipseA) + (y * y) / (ellipseB * ellipseB) >= 1) 
        {
            float angleCoef = (ellipseB * ellipseB * x) / (ellipseA * ellipseA * y);
            float yOffset = -(ellipseB * ellipseB) / y;
            float randomCoef = rand() % 100 * 0.01;
            float randomCoef2 = sqrt(1 - randomCoef * randomCoef);
            if (angleCoef > 0 && yOffset > 0)
            {
                moveFactor.x = randomCoef * speed;
                moveFactor.y = randomCoef2 * speed;
            }
            else if (angleCoef > 0 && yOffset < 0)
            {
                moveFactor.x = -randomCoef * speed;
                moveFactor.y = -randomCoef2 * speed;
            }
            else if (angleCoef < 0 && yOffset > 0)
            {
                moveFactor.x = -randomCoef * speed;
                moveFactor.y = randomCoef2 * speed;
            }
            else
            {
                moveFactor.x = randomCoef * speed;
                moveFactor.y = -randomCoef2 * speed;
            }
        }

        point.move(moveFactor);

        window.clear(Color(250, 250, 100, 255));
        window.draw(ellipse);
        window.draw(point);
        window.display();
    }

    return 0;
}