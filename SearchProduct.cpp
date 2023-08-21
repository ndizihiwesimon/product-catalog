#include "FileHandler.cpp"

class SearchProduct
{
private:
    string filename;

public:
    string searchText;
    FileHandler fHandler;

    string to_lowercase(const string& text) {
        string lowercase_text;
        for (char c : text) {
            lowercase_text += tolower(c);
        }
        return lowercase_text;
    }

    vector<Product> searchByName(string name){

        // TODO
        //Add code to search by name. Searching is not case sensitive it means
        //for input like: "name" products with names like "Name 1", "Product name" needs to included in the found results.
        vector<Product> searchResults;

        string lowercaseName = to_lowercase(name);
        for (Product& product : fHandler.readJsonFile()){
            string lowercaseProductName = to_lowercase(product.getName());
            if(lowercaseProductName.find(lowercaseName) != string::npos){
                searchResults.push_back(product);
            }
        }
        return searchResults;
    
    };

    vector<Product> searchByCategory(string categ){

        // TODO
        //Add code to search by category. Searching is not case sensitive it means 
        //for input like: "categ" products with category like "category 1", "Product category" needs to included in the found results.
        vector<Product> result;
        string lowercaseCategory= to_lowercase(categ);
        for(Product& product : fHandler.readJsonFile()){
            string lowercaseProductCat = to_lowercase(product.getCategory());
            if (lowercaseProductCat.find(lowercaseCategory)!=string::npos){
                result.push_back(product);
            }
        }
        return result;
    };

    vector<Product> searchByBrand(string brand){
      // TODO
        //Add code to search by brand. Searching is not case sensitive it means 
        //for input like: "br" products with names like "Brand 1", "brand name" needs to included in the found results.
        vector<Product> result;
        string lowercaseBrand = to_lowercase(brand);
        for (Product& product : fHandler.readJsonFile()){
            string lowercaseProductBrand = to_lowercase(product.getBrand());
            if(lowercaseProductBrand.find(lowercaseBrand) != string::npos){
                result.push_back(product);
            }
        }
        return result;
    };

    void showSearchResult(vector<Product> plist, string sTxt)
    {
        // TODO
        //Add code to display Search results
        int  i=1;
        cout<<endl<<"Showing results for "<<"\""<<sTxt<<"\""<<endl;
        for (Product& product : plist) {
            cout <<"\t"<<i<<". Code: " << product.getCode() << ", "<< "Name: " << product.getName() << ", "<< "Brand: " << product.getBrand() << ", "<< "Description: " << product.getDescription() << ", "<< "Dosage Instruction: " << product.getDosageInstruction() << ", "<< "Price: " << product.getPrice() << ", "<< "Quantity: " << product.getQuantity() << ", "<< "Category: " << product.getCategory() << ", "<< "Prescription: " << (product.getRequiresPrescription() ? "Yes" : "No") << endl;
            i++;
        }

    }
};