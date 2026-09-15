#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Texture
{
private:
    string name;
    int width;
    int height;

public:

    Texture(string n, int w, int h)
    {
        name = n;
        width = w;
        height = h;

        cout << "[Texture Loaded]" << endl;
    }

    ~Texture()
    {
        cout << "[Texture Released]" << endl;
    }

    void display() const
    {
        cout << "Texture : " << name << endl;
        cout << "Size : " << width
             << " x " << height << endl;
    }
};

int main()
{
    auto tex1 = make_unique<Texture>(
        "player_sprite", 512, 512);

    tex1->display();

    // unique_ptr<Texture> tex2 = tex1;
    // This gives an error because unique_ptr cannot be copied.

    unique_ptr<Texture> tex2 = move(tex1);

    cout << "tex1 is null: "
         << (tex1 == nullptr ? "YES" : "NO")
         << endl;

    tex2->display();

    return 0;
}