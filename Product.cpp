#include <iostream>
#include <string.h>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

class Product{

    private:
    int quantity;
    string name;
    string brand;
    string description;
    string code;
    float price;
    string dosageInstruction;
    string category;
    bool requires_prescription;

    public:

    string getCode(){
        return code;
    }
    string getName(){
        return name;
    }

    string getBrand(){
        return brand;

    }

    string getDescription(){
        return description;
    }

    string getDosageInstruction(){
        return dosageInstruction;

    }

    string getCategory(){
        return category;
    }
    
    int getQuantity(){
        return quantity;
    }

    float getPrice(){
        return price;
    }

    bool getRequiresPrescription(){
        return requires_prescription;
    }


    string generateUniqueCode()
    {
        string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        string uniqueCode = "";
        auto now = system_clock::now();
        auto millis = duration_cast<milliseconds>(now.time_since_epoch());
        mt19937 generator(millis.count());
        uniform_int_distribution<int> distribution(0, 100000);

        // generate 10 characters long unique string

        for (int i = 0; i <= 10; i++)
        {
            int random_index = distribution(generator) % characters.length();
            uniqueCode += characters[random_index];
        }

        return uniqueCode;
    };

    string promptTextField(string promptText){
        string user_input;
        cout << promptText;
        getline(cin, user_input);
        return user_input;
    }


    float promptNumberField(string promptText){
        float user_input;
        bool validInput = false;
        while (!validInput) {
            cout <<promptText;
            if (std::cin >> user_input) {
                validInput = true;
            } else {
                cout << "Invalid input. Please enter a valid float." << std::endl;
                cin.clear(); // Clear error flags
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            }
        }
        return user_input;
    }

    int promptNumberIntField(string promptText){
        int user_input;
        while (true) {
            cout << promptText;
            if (cin >> user_input) {
                // Input is a valid integer
                break; // Exit the loop
            } else {
                cout << "Invalid input. Please enter an integer." << std::endl;
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            }
        }
        return user_input;
    }
    bool promptRequirePrescription(string promptText)
    {
        int user_input;
        // User can type 1 or 0.
        cout << promptText;
        cin >> user_input;

        if (user_input==1){
            return 1;
        } else if (user_input==0) {
            return 0;
        } else {
            cout << "Please select between 1 and 0";
        }
        // it prompts a user and return user input in form of boolean.
    }

    void createProduct()
    {
        cin.ignore();
        this->code = generateUniqueCode();
        this->name = promptTextField("Enter Product Name: ");
        this->brand = promptTextField("Enter Product Brand: ");
        this->category = promptTextField("Enter Product Category: ");
        this->description= promptTextField("Enter Product Description: ");
        this->dosageInstruction= promptTextField("Enter Product Dosage Instructions: ");
        this->quantity = promptNumberIntField("Enter Product Quantity: ");
        this->price = promptNumberField("Enter Product Price: ");
        this->requires_prescription= promptRequirePrescription("Does the Product Require a Prescription? Enter 1 or 0: ");



        // Add code to generate Unique code for product using generateUniqueCode method

    };

    string toJson()
    {

        string productInJson;

      productInJson = "{\"code\":\"" ;
      productInJson += code;
      productInJson += "\",\"name\":\"";
      productInJson += name;
      productInJson += "\",\"brand\":\"";
      productInJson += brand;
      productInJson += "\",\"description\":\"";
      productInJson += description;
      productInJson +=  "\",\"dosage_instruction\":\"";
      productInJson += dosageInstruction;
      productInJson += "\",\"price\":";
      productInJson +=  std::to_string(price);
      productInJson += ",\"quantity\":";
      productInJson += std::to_string(quantity);
      productInJson +=  ",\"category\":\"";
      productInJson += category;
      productInJson += "\",\"requires_prescription\":";
      productInJson +=  std::to_string(requires_prescription);
      productInJson +=  "}";

        return productInJson;
    };

    void productFromJson(string txt) {
        size_t start, end;

        start = txt.find("\"code\":\"");
        end = txt.find("\"", start + 8);
        code = txt.substr(start + 8, end - start - 8);

        start = txt.find("\"name\":\"");
        end = txt.find("\"", start + 8);
        name = txt.substr(start + 8, end - start - 8);

        start = txt.find("\"brand\":\"");
        end = txt.find("\"", start + 9);
        brand = txt.substr(start + 9, end - start - 9);

        start = txt.find("\"description\":\"");
        end = txt.find("\"", start + 15);
        description = txt.substr(start + 15, end - start - 15);

        start = txt.find("\"dosage_instruction\":\"");
        end = txt.find("\"", start + 22);
        dosageInstruction = txt.substr(start + 22, end - start - 22);

        start = txt.find("\"price\":");
        end = txt.find(",", start + 8);
        price = stof(txt.substr(start + 8, end - start - 8));

        start = txt.find("\"quantity\":");
        end = txt.find(",", start + 11);
        quantity = stoi(txt.substr(start + 11, end - start - 11));

        start = txt.find("\"category\":\"");
        end = txt.find("\"", start + 12);
        category = txt.substr(start + 12, end - start - 12);

//        start = txt.find("\"requires_prescription\":");
//        end = txt.find("}", start + 24);
//        requires_prescription = stoi(txt.substr(start + 24, end - start - 24));

        start = txt.find("\"requires_prescription\":") + 24;
        std::string find_me = std::string (txt.substr(start, txt.find("}")));
        requires_prescription= std::stoi(find_me);

    };
};
