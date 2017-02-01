#include<iostream>
#include<sstream>
#include<vector>

template <typename T>
void outputVector(std::vector<T> input){
	std::cout << "[";
	for(int i = 0; i < input.size(); i++){
		std::cout << input[i];
		if(i != input.size()-1){
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
}

int binarySearch(std::vector<double> input, double target, int startIndex = 0){
	if(input.size() < 2){
		//std::cout << "Could not find middle";
		return startIndex;
	}

	int middleIndex = int(input.size())/2;
	double middle = input[middleIndex];
	
	if(target == middle){
		return middleIndex + startIndex; 
	}
	else if(target < middle){
		std::vector<double>::const_iterator begin = input.begin();
		std::vector<double>::const_iterator last = input.begin() + middleIndex;
		std::vector<double> firstHalf(begin, last);
		//std::cout << "First Half: ";
		//outputVector(firstHalf);
		return binarySearch(firstHalf, target, startIndex);
	}
	else if(target > middle){
		std::vector<double>::const_iterator begin = input.begin() + middleIndex + 1;
		std::vector<double>::const_iterator last = input.begin() + input.size();
		std::vector<double> secondHalf(begin, last);
		//std::cout << "Second Half: ";
		//outputVector(secondHalf);
		return binarySearch(secondHalf, target, startIndex+middleIndex+1);
	}
	else{
		return -1;
	}
}


std::vector<double> doubleVectorInput(){
	std::string inputString;
	getline(std::cin, inputString);
	std::vector<double> array;
	std::istringstream iss(inputString);
	float val;
	while(iss >> val){
		array.push_back(val);
	}
	return array;  	
}

int main(){
	double target;
	std::cout << "Vector to search: ";
	std::vector<double> input = doubleVectorInput();
	std::cout << "Target: "; std::cin >> target;
	std::cout << "Target index: " << binarySearch(input, target) << "\n";
	return 0;
}
