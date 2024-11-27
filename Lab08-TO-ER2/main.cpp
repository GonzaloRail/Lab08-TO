#include <iostream>
#include <memory>

// Forward declarations
class AbstractProductoA;
class AbstractProductoB;

class AbstractFactory {
public:
    virtual std::unique_ptr<AbstractProductoA> CrearProductoA() const = 0;
    virtual std::unique_ptr<AbstractProductoB> CrearProductoB() const = 0;
    virtual ~AbstractFactory() = default;
};

class AbstractProductoA {
public:
    virtual ~AbstractProductoA() = default;
    virtual std::string Funcion1_A() const = 0;
};

class CProductoA1 : public AbstractProductoA {
public:
    std::string Funcion1_A() const override {
        return "Producto A1.";
    }
};

class CProductoA2 : public AbstractProductoA {
public:
    std::string Funcion1_A() const override {
        return "Producto A2.";
    }
};

class AbstractProductoB {
public:
    virtual ~AbstractProductoB() = default;
    virtual std::string Funcion1_B() const = 0;
    virtual std::string Funcion2_B(const AbstractProductoA& colaborador) const = 0;
};

class CProductoB1 : public AbstractProductoB {
public:
    std::string Funcion1_B() const override {
        return "Producto B1.";
    }
    std::string Funcion2_B(const AbstractProductoA& colaborador) const override {
        const std::string result = colaborador.Funcion1_A();
        return "B1 con ayuda de " + result;
    }
};

class CProductoB2 : public AbstractProductoB {
public:
    std::string Funcion1_B() const override {
        return "Producto B2.";
    }
    std::string Funcion2_B(const AbstractProductoA& colaborador) const override {
        const std::string result = colaborador.Funcion1_A();
        return "B2 con ayuda de " + result;
    }
};

class CFactory1 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductoA> CrearProductoA() const override {
        return std::make_unique<CProductoA1>();
    }
    std::unique_ptr<AbstractProductoB> CrearProductoB() const override {
        return std::make_unique<CProductoB1>();
    }
};

class CFactory2 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductoA> CrearProductoA() const override {
        return std::make_unique<CProductoA2>();
    }
    std::unique_ptr<AbstractProductoB> CrearProductoB() const override {
        return std::make_unique<CProductoB2>();
    }
};

void Cliente(const AbstractFactory& f) {
    auto producto_a = f.CrearProductoA();
    auto producto_b = f.CrearProductoB();

    std::cout << producto_b->Funcion1_B() << "\n";
    std::cout << producto_b->Funcion2_B(*producto_a) << std::endl;
}

int main() {
    std::cout << "Cliente: Tipo 1" << std::endl;
    CFactory1 f1;
    Cliente(f1);

    std::cout << std::endl;

    std::cout << "Cliente: Tipo 2" << std::endl;
    CFactory2 f2;
    Cliente(f2);

    return 0;
}
