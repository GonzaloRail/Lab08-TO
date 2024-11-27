#include <iostream>
#include <string>
#include <vector>

// Clase base Abstracta para Recetas
class Recipe {
protected:
    std::string name;
    std::vector<std::string> ingredients;
    std::string origin;
    int difficulty;

public:
    virtual void prepareIngredients() = 0;
    virtual void cookMethod() = 0;
    virtual void plate() = 0;
    virtual void displayRecipe() = 0;

    virtual ~Recipe() {}
};

// Receta de Cocina Mexicana
class MexicanRecipe : public Recipe {
public:
    MexicanRecipe() {
        name = "Tacos al Pastor";
        origin = "Mexico";
        difficulty = 3;
    }

    void prepareIngredients() override {
        ingredients = {
            "Tortillas de maiz",
            "Carne de cerdo marinada",
            "Pina",
            "Cebolla",
            "Cilantro"
        };
        std::cout << "Preparando ingredientes para " << name << std::endl;
    }

    void cookMethod() override {
        std::cout << "Cocinando al estilo tradicional mexicano en trompo" << std::endl;
    }

    void plate() override {
        std::cout << "Sirviendo tacos con guarnición" << std::endl;
    }

    void displayRecipe() override {
        std::cout << "Receta: " << name << std::endl;
        std::cout << "Origen: " << origin << std::endl;
        std::cout << "Dificultad: " << difficulty << "/5" << std::endl;

        std::cout << "Ingredientes:" << std::endl;
        for(const auto& ingredient : ingredients) {
            std::cout << "- " << ingredient << std::endl;
        }
    }
};

// Receta de Cocina Italiana
class ItalianRecipe : public Recipe {
public:
    ItalianRecipe() {
        name = "Pasta Carbonara";
        origin = "Italia";
        difficulty = 2;
    }

    void prepareIngredients() override {
        ingredients = {
            "Pasta",
            "Huevos",
            "Panceta",
            "Queso Pecorino",
            "Pimienta negra"
        };
        std::cout << "Preparando ingredientes para " << name << std::endl;
    }

    void cookMethod() override {
        std::cout << "Cocinando al estilo tradicional italiano" << std::endl;
    }

    void plate() override {
        std::cout << "Sirviendo pasta con queso rallado" << std::endl;
    }

    void displayRecipe() override {
        std::cout << "Receta: " << name << std::endl;
        std::cout << "Origen: " << origin << std::endl;
        std::cout << "Dificultad: " << difficulty << "/5" << std::endl;

        std::cout << "Ingredientes:" << std::endl;
        for(const auto& ingredient : ingredients) {
            std::cout << "- " << ingredient << std::endl;
        }
    }
};

// Receta de Cocina Japonesa
class JapaneseRecipe : public Recipe {
public:
    JapaneseRecipe() {
        name = "Ramen";
        origin = "Japon";
        difficulty = 4;
    }

    void prepareIngredients() override {
        ingredients = {
            "Fideos de ramen",
            "Caldo de cerdo",
            "Huevo",
            "Chashu (cerdo)",
            "Algas nori",
            "Cebollin"
        };
        std::cout << "Preparando ingredientes para " << name << std::endl;
    }

    void cookMethod() override {
        std::cout << "Preparando caldo y montando el ramen" << std::endl;
    }

    void plate() override {
        std::cout << "Sirviendo ramen caliente en un tazon" << std::endl;
    }

    void displayRecipe() override {
        std::cout << "Receta: " << name << std::endl;
        std::cout << "Origen: " << origin << std::endl;
        std::cout << "Dificultad: " << difficulty << "/5" << std::endl;

        std::cout << "Ingredientes:" << std::endl;
        for(const auto& ingredient : ingredients) {
            std::cout << "- " << ingredient << std::endl;
        }
    }
};

// Fábrica de Recetas
class RecipeFactory {
public:
    static Recipe* createRecipe(int type) {
        Recipe* recipe = nullptr;

        switch(type) {
        case 1: recipe = new MexicanRecipe(); break;
        case 2: recipe = new ItalianRecipe(); break;
        case 3: recipe = new JapaneseRecipe(); break;
        default:
            std::cout << "Tipo de receta invalido" << std::endl;
            return nullptr;
        }

        recipe->prepareIngredients();
        recipe->cookMethod();
        recipe->plate();

        return recipe;
    }
};

// Programa principal
int main() {
    int type;
    while(true) {
        std::cout << "\nSeleccione un tipo de receta:" << std::endl;
        std::cout << "1. Receta Mexicana" << std::endl;
        std::cout << "2. Receta Italiana" << std::endl;
        std::cout << "3. Receta Japonesa" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Ingrese su opcion: ";

        std::cin >> type;

        if(type == 0) break;

        Recipe* recipe = RecipeFactory::createRecipe(type);

        if(recipe) {
            recipe->displayRecipe();
            delete recipe;
        }
    }

    std::cout << "Saliendo del programa..." << std::endl;
    return 0;
}
