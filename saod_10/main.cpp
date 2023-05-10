
#include "stdafx.h"
#include "COBS.h"
#include "RLE.h"
int main()
{

	char cOperation;
	cout << "Enter the first letter of the operation (c - compression; d - decompression):";
	cin >> cOperation; cin.get();

	if (cOperation != 'c' && cOperation != 'd') {
		printf("Error: can't recognize this operation!...\n");
		return -1;
	}

	string sFInName, sFOutName;

	cout << "Enter name of Input File:" << endl;
	getline(cin, sFInName);
	cout << "Enter name of Output File:" << endl;
	getline(cin, sFOutName);

	//  Определим размер файла в байтах
	struct stat stat_buf;
	int rc = stat(sFInName.c_str(), &stat_buf);
	if (rc == -1)
		cout << "can't open '" << sFInName << "'" << endl;
	unsigned int inLen = stat_buf.st_size;

	// Выделим буфер под чтение файла
	char *buf = new char[inLen];

	// Прочтем файл в бинарной моде в буфер.
	ifstream ifs;
	ifs.open(sFInName, ios_base::binary);
	if (ifs.is_open())
	{
		ifs.read(buf, inLen);
		ifs.close();
	}
	RLE rl;
	//  Пример COBS-кодирования/декдирования
	char *tmp1 = new char[inLen];
	char *tmp2 = new char[inLen];

	cout << "coding length: " << inLen / 2 << endl;
	int len = COBSEncode((const unsigned char*)buf, inLen/2, (unsigned char*)tmp1);
	cout << "coded length: " << len << endl;
	len = COBSDecode((const unsigned char*)tmp1, len, (unsigned char*)tmp2);
	cout << "decoded length: " << len << endl;

	char* tmp3 = new char[inLen];
	char* tmp4 = new char[inLen];
	len = rl.RLEDeflate((const unsigned char*)buf, inLen / 2, (unsigned char*)tmp3);
	cout << "RLE LEN: " << len << endl;
	len = rl.RLEInflate((const unsigned char*)tmp3, len, (unsigned char*)tmp4);
	cout << "decoded RLE len: " << len << endl;
	delete[] buf;
	return 0;
}


