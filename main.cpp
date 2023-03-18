#include <string>
#include <iostream>

//������� �������� ������ �� ��������� ����� K. ��������� ��������� ��������.

auto IsKPeriodic(std::string text, size_t K) 
{
	//�������� ��������� ����� ������ ����� K. ���� ����� �� ������ - ����������
	//"����" � ���������� ���������� ��������.

	if (text.size() % K != 0)
		return false;
	
	//����������� ������� ��������� ��� ��������.

	size_t range = text.size() / K;

	//�������� ������������� ��������� �������� � ��������� [0,range] � ����� 
	//range, ������� � ������� range � �� ����� ������. � ������ ���������� 
	//���������� ��������� � ������������ ��������� ������, ���������� ��������
	//� ���������� "����".

	for (size_t i = range; i < text.size(); i += range)
		if (text.substr(0, range) != text.substr(i, range)) 
			return false;

	//� ������ �������� �������� �� ��������� - ���������� "������".

	return true;
};

//������� ������ �� ����� �������� ������ � ����������� �������� �� ���������,
//����� ��������� � ������� IsKPeriodic � ��������� �������� ������.

void PrintInfo(std::string text, size_t K)
{
	system("cls");
	std::cout << "�������� ��������� ������ ����� K" << std::endl << std::endl;
	std::cout << "������: " << text << std::endl;
	std::cout << "����� K = " << K << std::endl;
	std::cout << "������ " << (IsKPeriodic(text, K) ? "" : "�� ")
		<< "������ ����� K" << std::endl << std::endl;
};

//�������� ���� ���������. ���������������� ���� �� 2-�� ������: 1 - ���� 
//������ � 2 - ����� �� ���������. �������� ����������� �������� ������ �
//������ ���������� ����� ������� �����, �� ������ ������� ������.

auto main() -> int
{
	system("chcp 1251");
	system("cls");
	std::cout << "�������� ��������� ������ ����� K" << std::endl << std::endl;
	size_t command = NULL;
	
	do
	{
		
		//���������������� ���� �� 2-�� ������, � ����������� ������ �� ����� 
		//�� ��������������� ���������� ������.

		std::cout << "������� 1 - ��� ����� ������ ��� 2 - ��� ������: ";
		while (!(std::cin >> command) || (std::cin.peek() != '\n') || !(command == 1
			|| command == 2))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "�� ����� �������� ����� ��������. ��������� ����: "
				<< std::endl;
		}
		
		//���������� ������ 1 ������ ����������������� ����. ���� �������� ������ 
		//��� �������� �� ���������. ����������� ������ �� ����� �������� ����� K, 
		//�� ����������������� �������� ������: ������������� �����, ������ ����.

		if (command == 1)
		{
			std::string text;
			size_t K = NULL;
			std::cout << "������� ����������� ������:" << std::endl;
			std::cin.ignore();
			std::getline(std::cin, text);
			std::cout << "������� ����� ����� K (K ������ ���� ������ 0): ";
			while (!(std::cin >> K) || (std::cin.peek() != '\n') || !(K > 0))
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				std::cout << "�� ����� �������� ����� K. ����������, ��������� ����: "
					<< std::endl;
			}

			//����� ������� ������ �� ����� ����������� ��������.

			PrintInfo(text, K);
		}
	} while (command == 1);
	
	return 0;
}