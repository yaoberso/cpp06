#ifndef DATA_HPP
#define DATA_HPP

class Data {
	public:
		Data();
		Data(int nb);
		Data &operator=(Data &other);
		~Data();
		int get_data();
	private:
		int data;
};

#endif