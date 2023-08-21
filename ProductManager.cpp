#include "SearchProduct.cpp"
class ProductManager
{
private:
    Product prod;
public:
    FileHandler fileHandler;
    int getMenu(){
        SearchProduct searchProduct;
        Product product;
        vector<Product> searchResults;
        string sTxt;
        int choice;
        string productName;
        string productBrand;
        string productCategory;

        while(true){
            cout << "\n\n Menu :\n";
            cout << "\t\t 1) Add Product \n";
            cout << "\t\t 2) Search Product By Name \n";
            cout << "\t\t 3) Search Product by Category \n";
            cout << "\t\t 4) Search Product By Brand \n";
//        cout << "\t\t 5) Update Product \n";
//        cout << "\t\t 6) Delete Product \n";
            cout << "\t\t 5) Exit \n\n";
            cout << "\t\t Please Select an option! (1-7) : ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addProduct();
                    break;
                case 2:
                    cin.ignore();
                    sTxt =product.promptTextField("Enter Product Name: ");
                    searchResults = searchProduct.searchByName(sTxt);
                    searchProduct.showSearchResult(searchResults, sTxt);
                    break;
                case 3:
                    cin.ignore();
                    sTxt =product.promptTextField("Enter Product Category: ");
                    searchResults = searchProduct.searchByCategory(sTxt);
                    searchProduct.showSearchResult(searchResults, sTxt);
                    break;
                case 4:
                    cin.ignore();
                    sTxt =product.promptTextField("Enter Product Brand: ");
                    searchResults = searchProduct.searchByBrand(sTxt);
                    searchProduct.showSearchResult(searchResults, sTxt);
                    break;
//            case 5:
//                updateProduct();
//                break;
//            case 6:
//                deleteProduct();
//                break;
                case 5:
                    cout<<"Exiting..."<<endl;
                    return 0;
                default:
                    std::cout << "Invalid choice! please select a valid option" << std::endl;
                    break;
            }
        }
    }

    void addProduct(){
        prod.createProduct();
        fileHandler.saveToJsonFile(prod);
    }

    // TODO Add code for Updating a product
    void updateProduct(){
        // TODO add code to update product
        // store the product to products.json file by using Product class and FileHandler class
    }

    // TODO Add code for deleting a product
    void deleteProduct(){
        // TODO add code to delete product and
        // store the product to products.json file by using Product class and FileHandler class
    }
};

int main()
{
    ProductManager m;
    m.getMenu();
}


