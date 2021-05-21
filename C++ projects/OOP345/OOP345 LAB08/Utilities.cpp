//Name: Lara Fahmi
//Student Number: 109742197


// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		for (size_t i = 0; i < desc.size(); ++i) {
			for (size_t j = 0; j < price.size(); ++j) {
									//compares the elements in the two received lists for common product codes
				if (desc[i].code == price[j].code) {
									//allocates dynamic memory of Product type using that descriptionand the price
					Product* product = new Product(desc[i].desc, price[j].price);
									//validates the Product object
					product->validate();
									//adds it to its list
					priceList += product;
					delete product;
				}
			}
		}
		//Your function returns a copy of this list.
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers

		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					std::unique_ptr<Product> product( new Product(desc[i].desc, price[j].price) );
					product->validate();
					priceList += product;

				}
			}
		}


		return priceList;
	}
}