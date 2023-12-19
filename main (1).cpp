#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

template <typename T1, typename T2>
class Pair {
public:
    Pair() {}
    Pair(const T1& first, const T2& second) : first(first), second(second) {}

    void displayPair() const {
        std::cout << first << ": " << second << std::endl;
    }

    void savePairToFile(std::ofstream& outFile) const {
        outFile << first << " " << second << " ";
    }

private:
    T1 first;
    T2 second;
};



class Product {
public:
    Product(const std::string& Name, const double& Price, const int& Quantity)
        : Name(Name), Price(Price), Quantity(Quantity) {}

    ~Product() {}
    
    const std::string& getName() const {
        return Name;
    }

    const double& getPrice() const {
        return Price;
    }
    
    const int& getQuantity() const {
		return Quantity;
	}

    void setName(const std::string& newName) {
        Name = newName;
    }

   
    void setPrice(const double& newPrice) {
        Price = newPrice;
    }
    
    void setQuantity(const int& newQuantity) {
        Quantity = newQuantity;
	}

    void displayInfo() const {
        std::cout << "Ïðîäóêò: " << Name << ", Öåíà: " << Price << " Êîë-âî: " << Quantity;
        grades.displayGrades();
    }

    
    void saveToFile(std::ofstream& outFile) const {
    	outFile << Name << " " << Price << " " << Quantity << " ";
        grades.saveGradesToFile(outFile);
    }

    void modifyProduct(const std::string&Name) {
        std::cout << "Продукты, что вы хотите в них изменить?" << std::endl
        std::cout << "1 Имя"
        std::cout << "2 Цена"
        std::cout << "3 Количество"

		
	int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string Name;
                double Price;
                int Quantity;

                std::cout << "Ââåäèòå äàííûå ïðîäóêòà:" << std::endl;
                std::cout << "Íàçâàíèå: ";
                std::cin >> Name;
                std::cout << "Öåíà: ";
                std::cin >> Price;
                std::cout << "Êîë-âî: ";
                std::cin >> Quantity;

                products.push_back(new Product(Name, Price, Quantity));
                products.back()->inputGrades();

                break;
            }
            case 2: {
                std::string Name;
                std::cout << "Ââåäèòå äàííûå ïðîäóêòà äëÿ ïîèñêà:" << std::endl;
                std::cout << "Ïðîäóêò: ";
                std::cin >> Name;

                auto it = std::find_if(products.begin(), products.end(), [&](const Product* product) {
                    return product->getName() == Name;
                });

                if (it != products.end()) {
                    (*it)->displayInfo();
                } else {
                    std::cout << "Ïðîäóêò íå íàéäåí." << std::endl;
                }

                break;
            }
             case 3: {
                std::cout << "Ââåäèòå íàçâàíèå ôàéëà: ";
                std::cin >> filename;
                saveProductsToFile(products, filename);
                break;
            }
            case 4:
                std::cout << "Âûõîä." << std::endl;
                break;
            default:
                std::cout << "Íåâåðíûé âûáîð." << std::endl;
        }
    } while (choice != 4);


void saveProductsToFile(const std::vector<Product*>& products, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Ââåäèòå èìÿ ôàéëà." << std::endl;
        return;
    }

    for (const auto* product : products) {
        product->saveToFile(outFile);
    }

    outFile.close();
}
int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<Product*> products;

    int choice;
    std::string filename;

    do {
        std::cout << "Ìåíþ:" << std::endl;
        std::cout << "1. Äîáàâèòü ïðîäóêò" << std::endl;
        std::cout << "2. Íàéòè ïðîäóêò" << std::endl;
        std::cout << "3. Ñîõðàíèòü â ôàéë" << std::endl;
        std::cout << "4. Âûõîä" << std::endl;

        std::cout << "Ââåäèòå âàø âûáîð: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string Name;
                double Price;
                int Quantity;

                std::cout << "Ââåäèòå äàííûå ïðîäóêòà:" << std::endl;
                std::cout << "Íàçâàíèå: ";
                std::cin >> Name;
                std::cout << "Öåíà: ";
                std::cin >> Price;
                std::cout << "Êîë-âî: ";
                std::cin >> Quantity;

                products.push_back(new Product(Name, Price, Quantity));
                products.back()->inputGrades();

                break;
            }
            case 2: {
                std::string Name;
                std::cout << "Ââåäèòå äàííûå ïðîäóêòà äëÿ ïîèñêà:" << std::endl;
                std::cout << "Ïðîäóêò: ";
                std::cin >> Name;

                auto it = std::find_if(products.begin(), products.end(), [&](const Product* product) {
                    return product->getName() == Name;
                });

                if (it != products.end()) {
                    (*it)->displayInfo();
                } else {
                    std::cout << "Ïðîäóêò íå íàéäåí." << std::endl;
                }

                break;
            }
             case 3: {
                std::cout << "Ââåäèòå íàçâàíèå ôàéëà: ";
                std::cin >> filename;
                saveProductsToFile(products, filename);
                break;
            }
            case 4:
                std::cout << "Âûõîä." << std::endl;
                break;
            default:
                std::cout << "Íåâåðíûé âûáîð." << std::endl;
        }
    } while (choice != 4);

    for (const auto* product : products) {
        delete product;
    }

    return 0;
}
