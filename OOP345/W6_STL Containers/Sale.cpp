#include "Sale.h"

namespace w7 {
	Sale::Sale(const char* name) {
		std::ifstream file;
		file.open(name);
		if (file.good()) {
			int n = getFileLine(file);
			file.clear();
			file.seekg(0, std::ios::beg);
			for (int i = 0; i < n; i++)
			{
				prdtList.push_back(readProduct(file));
			}
		}
	}
		
	void Sale::display(std::ostream& os) const {
		double total=0.0;
		os << "Product No" <<std::setw(10)<< "Cost";
		os << " Taxable"<<std::endl;
		os.precision(2);
		for (unsigned i = 0; i < prdtList.size(); i++)
		{
			os << *prdtList[i] << std::endl;
			total+=prdtList[i]->getCharge();
		}
		os << std::setw(10) << "Total";
		os << std::setw(10) << std::fixed << total;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& prdt) {
		prdt.display(os);
		return os;
	}
	iProduct* readProduct(std::ifstream& file) {
		iProduct* retProduct;
		int prdtNo;
		double price;
		char taxType;
		char type;
		size_t pos = 0u;
		size_t count = 0u;
		std::string line;
		std::getline(file, line);
		if (line.length() > 11) {
			type = 't';
		}
		else type = 'p';
		while ((pos = line.find(' '))!= std::string::npos) {
			if (count == 0u) {
				prdtNo = stoi(line.substr(0, pos));
			}
			else if (count == 1u) {
				price = stod(line.substr(0, pos));
			}
			line.erase(0, pos + 1);
			count++;
		}
		if (count==1u) price = stod(line);
		else if (count == 2u) taxType = line[0];
		if (type == 't') {
			retProduct = new TaxableProduct(prdtNo, price, taxType);
		}
		else {
			retProduct = new Product(prdtNo, price);
		}
		return retProduct;
	}

	int getFileLine(std::ifstream& fin) {
		std::string temp;
		int numberOfLines = 0;
		while (std::getline(fin, temp))
		{
			numberOfLines++;
		}
		return numberOfLines;
	}
}