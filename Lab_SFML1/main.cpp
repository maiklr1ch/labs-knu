#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(600, 600), "Lab 2.2", Style::Close);
    VertexArray triangle(Triangles, 3);

    triangle[0].position = Vector2f(300.f, 120.f);
    triangle[1].position = Vector2f(120.f, 500.f);
    triangle[2].position = Vector2f(500.f, 500.f);

    for (int i = 0; i < 3; i++)
        triangle[i].color = Color::Green;
    float rotationFactor = 0, scaleFactor = 1;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        rotationFactor += 0.01f;
        if (scaleFactor < -1) scaleFactor = 1.f;
        else scaleFactor -= 0.0001f;

        Transform triangleTransform;
        triangleTransform.rotate(rotationFactor, Vector2f(300.f, 300.f));
        triangleTransform.scale(Vector2f(scaleFactor, scaleFactor), Vector2f(300.f, 300.f));

        window.clear();
        window.draw(triangle, triangleTransform);
        window.display();
    }

    return 0;
}