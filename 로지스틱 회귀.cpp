#include <iostream>
#include <vector>
#include <cmath>

// input(X) type
using dataType = double;

// learning_rate = 0.001
constexpr double learning_rate = 1e-3;

		@author https://mawile.tistory.com/202
		@param (첫번째행렬, 세로길이1, 가로길이1, 두번째행렬, 세로길이2, 가로길이2)
template<typename vecType>
std::vector<std::vector<vecType>> matmul(
		std::vector<std::vector<vecType>> arr1, int row1, int col1,
		std::vector<std::vector<vecType>> arr2, int row2, int col2){
			
	std::vector<std::vector<vecType>> result(row1, std::vector<vecType>(col2));
	
	for(int i=0;i<row1;++i){
		for(int j=0;j<col2;++j){
			vecType sum = 0.0;
			for(int k=0;k<row2;++k) sum += arr1[i][k] * arr2[k][j];
			result[i][j] = sum;
		}
	}
	
	return result;
}

		@brief sigmoid function
double sigmoid(double z){
	// https://www.HostMath.com/Show.aspx?Code=%5Cfrac%7B1%7D%7B1%20%2B%20e%5E%7B-z%7D%7D
	return 1.0 / (1.0 + std::exp(-z));
}

		@brief gradient descent
*/
std::vector<double> GradientDescent(std::vector<std::vector<dataType>>& X, std::vector<std::vector<dataType>>& Y, std::vector<std::vector<dataType>>& W, double& b, double lr){
	const int m = Y.size() * W[0].size(); // The length of the arrangement.
	const int row1 = X.size(); // axis = 0
	const int col1 = X[0].size(); // axis = 1
	const int row2 = W.size(); // axis = 0
	const int col2 = W[0].size(); // axis = 1
	
	std::vector<double> lossList; // Arrangement of the loss function result.
	
	if(m != X.size() *  W[0].size()) throw std::runtime_error("The sizes of X and Y are not right");
	
	// matrics multiplication
	auto matmulWX = matmul(X, row1, col1, W, row2, col2);
	
	// calulate dW and db
	for(int i=0;i<row1;++i){
		double loss = 0, dW = 0, db = 0;
		
		for(int j=0;j<col2;++j){
			// Hypothesis
			double H = sigmoid(matmulWX[i][j] + b);
			
			// sigma dW
			dW += (H - Y[i][j]) * X[i][j];
			
			// sigma db
			db += H - Y[i][j];
		}
		
		// https://www.HostMath.com/Show.aspx?Code=%5Cfrac%7B1%7D%7Bm%7D%5Csum_%20%7Bi%3D1%7D%5Em(H%20-%20Y_%7Bi%7D)%20%5Ccdot%20X_%7Bi%7D
		dW = dW / m; // m = row1 * col2
		
		// https://www.HostMath.com/Show.aspx?Code=%5Cfrac%7B1%7D%7Bm%7D%5Csum_%20%7Bi%3D1%7D%5Em(H%20-%20Y_%7Bi%7D)
		db = db / m; // m = row1 * col2
		
		// loss function
		for(int j=0;j<col2;++j){
			// hypothesis
			double H = sigmoid(matmulWX[i][j] + b);
		
			loss += (Y[i][j] * std::log(H) + (1 - Y[i][j]) * std::log(1 - H));
		}
		
		for(int i=0;i<row2;++i){
			for(int j=0;j<col2;++j){
				// weight and bias Update
				W[i][j] = W[i][j] - lr * dW;
				b = b - lr * db;
			}
		}
		
		// https://www.HostMath.com/Show.aspx?Code=-%5Cfrac%7B1%7D%7Bm%7D%5Csum_%20%7Bi%3D1%7D%5Em%5By%20%5Ccdot%20%5Clog_%7B%7D%7BH_%7Bi%7D%7D%20%2B%20(1%20-%20y)%20%5Ccdot%20%5Clog_%7B%7D%7B1%20-%20H_%7Bi%7D%7D%5D
		loss = loss / -m; // m = row1 * col2
		
		lossList.push_back(loss);
	}
	
	return lossList;
}

void LogisticRegression(std::vector<std::vector<dataType>>& X, std::vector<std::vector<dataType>>& Y, std::vector<std::vector<dataType>>& W, double& b, int epochs, double lr){
	int printTry = epochs / 10; // Print epochs as many times as the value divided by 10.
	
	for(int i=0;i<epochs;++i){
		auto loss = GradientDescent(X, Y, W, b, lr);
		if(i % printTry == 0){
			std::cout << "Weight: ";
			for(int i=0;i<W.size();++i) for(int j=0;j<W[0].size();++j) std::cout << W[i][j] << " ";
			std::cout << "\nBias: " << b << "\nLoss: ";
			for(int j=0;j<loss.size();++j) std::cout << loss[j] << ' ';
			std::cout << "\n\n";
		}
	}
}

std::vector<std::vector<int>> predict(std::vector<std::vector<dataType>>& W, double& b, std::vector<std::vector<dataType>> X){
	std::vector<std::vector<int>> result;
	
	// matrics multiplication
	auto matmulWX = matmul(X, X.size(), X[0].size(), W, W.size(), W[0].size());
	
	for(int i=0;i<X.size();++i){
		result.push_back(std::vector<int>());
		
		for(int j=0;j<W[0].size();++j){
			result[i].push_back((sigmoid(matmulWX[i][j] + b) < 0.5) ? 0 : 1);
		}
	}
	
	return result;
}

void printPrediction(std::vector<std::vector<int>> prediction){
	std::cout << "Prediction: ";
	for(int i=0;i<prediction.size();++i){
		for(int j=0;j<prediction[i].size();++j){
			std::cout << (prediction[i][j] == 0 ? "시험불합격예측..ㅠ" : "시험합격예측~!!") << ' ';
		}
		std::cout << '\n';
	}
}

double Accuracy(std::vector<std::vector<dataType>>& X, std::vector<std::vector<dataType>>& Y, std::vector<std::vector<dataType>>& W, double& b){
	// matrics multiplication
	auto matmulWX = matmul(X, X.size(), X[0].size(), W, W.size(), W[0].size());
	double sum = 0.0;
	
	for(int i=0;i<X.size();++i){
		for(int j=0;j<W[0].size();++j){
			// Hypothesis
			double H = sigmoid(matmulWX[i][j] + b);
			sum += (((H < 0.5) ? 0 : 1) == Y[i][j] ? 1 : 0);
		}
	}
	
	// 1/m * sigma((H < 0.5 ? 0 : 1) == Y[i][j] ? 1 : 0);
	return sum / static_cast<double>(X.size() * W[0].size());
}

int main() {
	srand(time(0));
	const dataType random_value = rand() % 20;  // random value
	
	std::vector<std::vector<dataType>> X =
	{
		{ 1.5, 2.2, 1.1 },
		{ 1.2, 3.5, 1.5 },
		{ 2.2, 2.9, 1.8 },
		{ 2.6, 2.1, 1.9 },
		{ 2.9, 1.1, 3.6 },
		{ 3.9, 0.5, 3.2 },
		{ 4.3, 4.9, 4.1 },
	};
	std::vector<std::vector<dataType>> Y =
	{
		{ 1 },
		{ 1 },
		{ 1 },
		{ 1 },
		{ 0 },
		{ 0 },
		{ 0 },
	};
	std::vector<std::vector<dataType>> W =
	{
		{ random_value },
		{ random_value },
		{ random_value },
	};
	double b = random_value;
	
	// train 30000 times
	LogisticRegression(X, Y, W, b, 30000, learning_rate);
	
	// prediction
	std::vector<std::vector<dataType>> nX = { { 3.2, 2.15, 1.9 } };
	
	printPrediction(predict(W, b, nX));
	
	auto accuracy = Accuracy(X, Y, W, b);
	
	std::cout.precision(12);
	std::cout << std::fixed  << "\nAccracy: " << accuracy << '(' << int(accuracy * 100) << "%)";
}