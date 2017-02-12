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


int binarySearch(std::vector<double> &input, double target, int startIndex = 0, int endIndex = -1){
	if(endIndex == -1){
		endIndex = input.size()-1;
	}
	if(startIndex == endIndex){
		return startIndex;
	}
	int middleIndex = (startIndex + endIndex)/2;

	
	if(target == input[middleIndex]){
		return middleIndex;
	}
	else if(target < input[middleIndex]){
		return binarySearch(input, target, startIndex, middleIndex-1);
	}
	else if(target > input[middleIndex]){
		return binarySearch(input, target, middleIndex+1, endIndex);
	}
}

int iterBinarySearch(std::vector<double> &input, double target){
	int endIndex = input.size()-1;
	int startIndex = 0;
	
	while(startIndex != endIndex){
		int middleIndex = (startIndex + endIndex)/2;
		
		if(target == input[middleIndex]){
			return middleIndex;
		}
		else if(target < input[middleIndex]){
			endIndex = middleIndex-1;
		}
		else if(target > input[middleIndex]){
			startIndex = middleIndex+1;
		}
	}
	return startIndex;
}



int main(){
	double target;
	std::cout << "Vector to search: ";
	std::vector<double> input = doubleVectorInput();
	std::cout << "Target: "; std::cin >> target;
	std::cout << "Target index: " << binarySearch(input, target) << "\n";
	return 0;
}
