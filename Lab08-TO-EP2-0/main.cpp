#include <iostream>
#include <string>
using namespace std;

// Interfaz abstracta para los botones
class Button {
public:
    virtual void Draw() const = 0; // Método virtual puro
    virtual ~Button() = default;
};

// Interfaz abstracta para los checkboxes
class CheckBox {
public:
    virtual void Draw() const = 0; // Método virtual puro
    virtual ~CheckBox() = default;
};

// Productos concretos para Windows
class WinButton : public Button {
public:
    void Draw() const override {
        cout << "Dibujando boton en Windows" << endl;
    }
};

class WinCheckBox : public CheckBox {
public:
    void Draw() const override {
        cout << "Dibujando checkbox en Windows" << endl;
    }
};

// Productos concretos para Mac
class MacButton : public Button {
public:
    void Draw() const override {
        cout << "Dibujando boton en Mac" << endl;
    }
};

class MacCheckBox : public CheckBox {
public:
    void Draw() const override {
        cout << "Dibujando checkbox en Mac" << endl;
    }
};

// Productos concretos para Linux
class LinuxButton : public Button {
public:
    void Draw() const override {
        cout << "Dibujando boton en Linux" << endl;
    }
};

class LinuxCheckBox : public CheckBox {
public:
    void Draw() const override {
        cout << "Dibujando checkbox en Linux" << endl;
    }
};

// Interfaz abstracta para la fábrica
class GUIFactory {
public:
    virtual Button* CreateButton() const = 0;
    virtual CheckBox* CreateCheckBox() const = 0;
    virtual ~GUIFactory() = default;
};

// Fábrica concreta para Windows
class WinFactory : public GUIFactory {
public:
    Button* CreateButton() const override {
        return new WinButton();
    }
    CheckBox* CreateCheckBox() const override {
        return new WinCheckBox();
    }
};

// Fábrica concreta para Mac
class MacFactory : public GUIFactory {
public:
    Button* CreateButton() const override {
        return new MacButton();
    }
    CheckBox* CreateCheckBox() const override {
        return new MacCheckBox();
    }
};

// Fábrica concreta para Linux
class LinuxFactory : public GUIFactory {
public:
    Button* CreateButton() const override {
        return new LinuxButton();
    }
    CheckBox* CreateCheckBox() const override {
        return new LinuxCheckBox();
    }
};

// Cliente
class Application {
private:
    Button* button;
    CheckBox* checkbox;

public:
    Application(const GUIFactory& factory) {
        button = factory.CreateButton();
        checkbox = factory.CreateCheckBox();
    }

    void DrawUI() const {
        button->Draw();
        checkbox->Draw();
    }

    ~Application() {
        delete button;
        delete checkbox;
    }
};

// Función principal
int main() {
    cout << "Cliente: Windows" << endl;
    WinFactory winFactory;
    Application app1(winFactory);
    app1.DrawUI();

    cout << "\nCliente: Mac" << endl;
    MacFactory macFactory;
    Application app2(macFactory);
    app2.DrawUI();

    cout << "\nCliente: Linux" << endl;
    LinuxFactory linuxFactory;
    Application app3(linuxFactory);
    app3.DrawUI();

    return 0;
}
