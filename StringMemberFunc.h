// [����Ʈ 11.12] ���ڿ� Ŭ���� ����ϱ�
////////////////////
//Homework by team
//
//Member functions of String class

// 0����Ʈ�� ���ڿ� �����ϴ� �⺻ ������
#include "String.h"
String::String()
{
	itsString = new char[1];
	itsString[0] = '\0';
	itsLen = 0;
}

// ����(helper) ������
// �ʿ��� ��ŭ�� ������ ���ڿ��� �����
// Ŭ���� �޽�忡 ���ؼ��� ����
String::String(unsigned short len)
{
	itsString = new char[len + 1];
	for (unsigned short i = 0; i <= len; i++)
		itsString[i] = '\0';
	itsLen = len;
}

// ���� �迭�� ���ڿ��� ��ȯ�� 
String::String(const char * const cString)
{
	itsLen = strlen(cString);
	size_t length = 0;
	itsString = new char[itsLen + 1];
	for (unsigned short i = 0; i<itsLen; i++)
		itsString[i] = cString[i];
	itsString[itsLen] = '\0';
}

// ���� ������
String::String(const String & rhs)
{
	itsLen = rhs.GetLen();
	itsString = new char[itsLen + 1];
	for (unsigned short i = 0; i<itsLen; i++)
		itsString[i] = rhs[i];
	itsString[itsLen] = '\0';
}
//�ε��� pos���� ����length��ŭ �����ϴ� ���� ������
String::String(const String& str, size_t pos, size_t length)
{
	itsLen = length;
	itsString = new char[itsLen + 1];
	for(size_t i = 0; i < itsLen; i++)
		itsString[i] = str[pos + i];
	itsString [itsLen] = '\0';
}
//str�迭�� �����ϴ� length ���̸�ŭ ������
String::String(const char* str, size_t length)
{
	itsLen = length;
	itsString = new char[itsLen + 1];
	for(unsigned short i = 0; i < itsLen; i++)
		itsString[i] = str[i];
	itsString[itsLen] = '\0';
}
//n���� ����c�� �����ϴ� ������
String::String(size_t n, char c)
{
	itsLen = n;
	itsString = new char[itsLen + 1];
	for(unsigned short i = 0; i < itsLen; i++)
		itsString[i] = c;
	itsString[itsLen] = '\0';
}
// �Ҹ���, �޸� ������
String::~String()
{
	delete[] itsString;
	itsLen = 0;
}

// ���� ������, ���� �޸� ������ 
// �׸��� ���ڿ��� ���̸� ���� 
String& String::operator=(const String & rhs)
{
	if (this == &rhs)
		return *this;
	delete[] itsString;
	itsLen = rhs.GetLen();
	itsString = new char[itsLen + 1];
	for (unsigned short i = 0; i<itsLen; i++)
		itsString[i] = rhs[i];
	itsString[itsLen] = '\0';
	return *this;
}

// ���� ���� ������ 
// ������ ������ ��ȯ�Ͽ�
// ���߿� �ٲ� �� �ְ� �� 
char & String::operator[](unsigned short offset)
{
	if (offset > itsLen)
		return itsString[itsLen - 1];
	else
		return itsString[offset];
}

// ��� ��ü�� ���Ǵ� 
// ��� ���� ������ 
char String::operator[](unsigned short offset) const
{
	if (offset > itsLen)
		return itsString[itsLen - 1];
	else
		return itsString[offset];
}

// ������ ���ڿ��� rhs�� �߰��Ͽ� 
// ���ο� ���ڿ��� ����
String String::operator+(const String& rhs)
{
	unsigned short i, totalLen = itsLen + rhs.GetLen();
	String temp(totalLen);
	for (i = 0; i<itsLen; i++)
		temp[i] = itsString[i];
	for (unsigned short j = 0; j<rhs.GetLen(); j++, i++)
		temp[i] = rhs[j];
	temp[totalLen] = '\0';
	return temp;
}

// ��ȯ�� ���� ������ ���ڿ� �ٲ� 
void String::operator+=(const String& rhs)
{
	unsigned short rhsLen = rhs.GetLen();
	unsigned short i, totalLen = itsLen + rhsLen;
	String temp(totalLen);
	for (i = 0; i<itsLen; i++)
		temp[i] = itsString[i];
	for (unsigned short j = 0; j<rhsLen; j++, i++)
		temp[i] = rhs[j];
	temp[totalLen] = '\0';
	*this = temp;
}

///////////////////
// Implement member functions here!!!(�����ڴ� ���� �ۼ��߽��ϴ�!)

//��ü�� itsString�� size�� �����ִ� �Լ�
size_t String::size() {
	size_t size = 0;
	while (itsString[size] != NULL)
		size++;
	return size;
}
//��ü�� itsString�� ���̸� �����ִ� �Լ�
size_t String::length()const {
	size_t length = 0;
	while (itsString[length] != NULL)
		length++;
	return length;
}
//��ü�� itsString�� ����ִ� �Լ�
void String::clear() {
	delete [] itsString; // ������ �������ִ� ���ڹ迭 �޸� ����
	itsString = new char[1]; // ���ο� �����޸� �Ҵ�
	itsString[0] = '\0'; // ���ο� ���ڹ迭 �ʱ�ȭ
	itsLen = 0;
}
//��ü�� itsString�� ����ִ��� Ȯ�����ִ� �Լ�
bool String::empty() {
		if (itsString[0] = '\0')//�迭�� 0��° �ε����� ���� �ΰ��̸� 0�� ��ȯ�ϰ�, �ƴϸ� 1�� ��ȯ�Ѵ�.
			return 0;
	return 1;
}
//��ü�� itsString�� �ε��� pos�� ���� ��ȯ�ϴ� �Լ�
char& String::at(size_t pos) {
	if(pos>=0 && pos<itsLen)
		return this-> itsString[pos];  // pos�� ���� 0���� ũ�ų� ���� itsLen���� ���� �� �� pos��ġ�� ���� ��ȯ�Ѵ�. 
	else
		return this-> itsString[itsLen]; // pos�� ���� if�� ���ǿ� �ش����� ������ �ι��ڸ� ��ȯ�Ѵ�. 
}
//��ü�� itsString�� ������ �ε����� ���� ��ȯ�ϴ� �Լ�
char& String::back() {
	return itsString[itsLen - 1];
}
//��ü�� itsString�� 0��° �ε����� ���� ��ȯ�ϴ� �Լ�
char& String::front() {
	return itsString[0];
}

//string�� string�� ��ġ�� �Լ�
String& String::append(const String& str) {
	unsigned short i, totalLen = itsLen + str.GetLen();
	char *temp = new char[itsLen]; // ���� �޸𸮸� �Ҵ��Ͽ� ���� ���ڿ��� temp �� �����Ѵ�.
	for (unsigned short j = 0; j < itsLen; j++) {
		temp[j] = itsString[j]; // ������ ���ڹ迭�� �Ҵ���� �޸𸮿� ������
	}
	delete[] itsString; // ���� ���ڹ迭 �����޸𸮸� ������

	itsString = new char[totalLen+1]; // ������ ���ڹ迭�� �μ��� ���� ���ڹ迭�� ���� �����޸𸮸� �Ҵ����
	for (i = 0; i < itsLen; i++) {
		itsString[i] = temp[i]; // ���� ���ڹ迭�� ������
	}
	for (unsigned short j = 0; j < str.GetLen(); i++, j++) {
		itsString[i] = str[j]; // �μ��� ���� ���ڹ迭�� ������
	}
	itsString[totalLen] = '\0'; // ������ �ε����� �ι��� ����
	itsLen = totalLen; // itsLen�� �� ���ڹ迭�� ��ģ ���̷� �缳��
	delete temp; // ������ ���ڹ迭�� �����س��� ���� �Ҵ�޾Ҵ� �����޸𸮸� ������
	return *this;
}

//string�� pos�ڸ��� �ٸ� string�� �����ϴ� �Լ�
String& String::insert(size_t pos, const String& str)
{
	unsigned short i, totalLen = itsLen + str.GetLen();
	char *temp = new char[itsLen]; // ���� ���ڹ迭�� �����س��� ���� �����޸𸮸� �Ҵ����
	for (unsigned short j = 0; j < itsLen; j++) {
		temp[j] = itsString[j]; // ������ ���ڹ迭�� �Ҵ���� �޸𸮿� ������
	}
	delete[] itsString; // ���� ���ڹ迭�� �޸𸮸� ������

	itsString = new char[totalLen+1]; // ������ ���ڹ迭�� �μ��� ���� ���ڹ迭�� ���� �����޸𸮸� �Ҵ����
	for (i = 0; i < pos; i++) { 
		itsString[i] = temp[i]; // pos�ε��� �������� ���� ���ڹ迭�� �״�� ������
	}
	for (unsigned short j = 0; j < str.GetLen(); i++, j++) { 
		itsString[i] = str[j]; // pos�ε������� �μ��� ���� ���ڹ迭�� ������
	}
	for (unsigned short k = pos; k < itsLen; i++, k++) { 
		itsString[i] = temp[k]; // ���� ���ڹ迭�� pos�ε��� ������ ���ڹ迭�� ������
	}
	itsString[totalLen] = '\0'; // ������ �ε����� �ι��� ����
	itsLen = totalLen; // itsLen�� �� ���ڹ迭�� ��ģ ���̷� �缳��
	delete [] temp; // ������ ���ڹ迭�� �����س��� ���� �Ҵ�޾Ҵ� �����޸𸮸� ������
	return *this; 
}

//string�� pos�ڸ����� len���̸�ŭ ����� �Լ�
String& String::erase (size_t pos, size_t len){
	size_t i, totalLen = itsLen - len; // totalLen�� ���� ������ itsLen���� ������ ������ len�� �� ������ �����Ѵ�.
	size_t finish_Erase = pos + len;  // ������ ����Ǵ� ������ ù ��° ������ ��ġ�� ������ ������ ���� ���� ���̴�. 
	
    char *temp = new char [totalLen+1];
    
    for(i=0; i<pos; i++)
	{
		temp[i] = itsString[i]; 
		// ���ο� ��ü temp�� ������ ��ġ �������� ���ڿ��� �Ű��ش�. 
	}
	
	for(i = pos ; i < totalLen; i++,finish_Erase++)
	{     
		temp[i] = itsString[finish_Erase]; 
		// itsString�� �ִ� ������ ���ڿ����� temp�� �־��ش�. 
	}
	
    delete[] itsString;  // itsString�� �ִ� �޸𸮸� �����Ѵ�.

    itsString = new char [totalLen+1]; // itsString�� �ٽ� �޸𸮸� totalLen+1��ŭ �Ҵ����ش�. 
    
   	for(i=0; i<totalLen; i++)
	{
    	itsString[i] = temp[i];  // itsString�� temp�� ���� ���ش�. 
    }
	itsString[totalLen] = '\0'; 	// itsString ���ڿ� ���� �ι��ڸ� �־��ش�. 

    delete[] temp; 	
	return *this;
}

//string�� pos�ڸ����� len���̸�ŭ str�� ��ü�ϴ� �Լ�
String& String::replace(size_t pos, size_t len, const String& str) {
	char * temp = new char [itsLen + 1];//��ü�� �迭�� �����ϱ� ���� �������� �޸𸮸� �Ҵ��Ѵ�.

	for (size_t i = 0; i < pos; i++)//0���� pos-1 �ε������� itsString�迭�� ���� �����Ѵ�.
		temp[i] = itsString[i];
	for (size_t i = pos; i < pos + len; i++)//pos���� (pos + len -1)�ε������� str�迭�� ���� �����Ѵ�.
		temp[i] = str[i - pos];
	for (size_t i = pos + len; i < itsLen; i++)//(pos + itsLen - 1)�ε������� itsString�迭�� ���� �����Ѵ�.
		temp[i] = itsString[i];
	delete [] itsString;//itsString�� �޸𸮸� �����Ѵ�.

	itsString = new char[itsLen + 1];//��ü�� �迭�� �ٽ� �����ϱ� ���� �޸𸮸� �������� �Ҵ��Ѵ�.

	for(size_t i = 0; i < itsLen; i++)//temp�迭�� itsString�� �����Ѵ�.
		itsString[i] = temp[i];

	delete [] temp;//�ӽù迭�� �޸𸮸� �����Ѵ�.
	return *this;
}

// �� ���ڿ��� swap�ϴ� �Լ�
void String::swap(String& str) {
   size_t i;
   int len = 0;
   // itsString�� ���̿� ���ڷι��� str�� ������ �� �� ���� ���� ���� len�� �ִ´�.
   if (itsLen > str.GetLen())
      len = itsLen;
   else
      len = str.GetLen();
   // �ӽ� �迭 ����
   char* tmp = new char[len + 1];
   // itsString�� �ִ� ���ڵ��� tmp �迭�� �ű��.
   for (i = 0; i < len; i++)
      tmp[i] = itsString[i];
   tmp[len] = '\0';
   // ������ �ִ� itsString�� �����ϰ� ���̰� len+1�� �迭�� �ٽ� �����Ѵ�.
   delete[] itsString;
   itsString = new char[len + 1];
   // str�� �ִ� ���ڵ��� itsString���� �ű��.
   for (i = 0; i < len; i++)
      itsString[i] = str[i];
   itsString[len] = '\0';
   // �ӽ� �迭 tmp�� �ִ�, �� ���� itsString�� �ִ� ���ڵ��� str�� �ű��.
   for (i = 0; i < len; i++)
      str[i] = tmp[i];
   str[len] = '\0';
   // �ӽ� �迭 tmp�� �����Ѵ�.
   delete[] tmp;
}

//string�� �ִ� �빮�ڸ� �ҹ��ڷ� �ٲٴ� �Լ�
String& String::lower() {
	for(size_t i = 0; i < itsLen; i++)
	{
		if(itsString[i] >= 'A' &&itsString[i] <= 'Z')
			itsString[i] += 'a' - 'A';
	}
	return *this;
}


//string�� �ִ� �ҹ��ڸ� �빮�ڷ� �ٲٴ� �Լ�
String& String::upper() {
	for(size_t i = 0; i < itsLen; i++)
	{
		if(itsString[i] >= 'a' &&itsString[i] <= 'z')
			itsString[i] -= 'a' - 'A';
	}
	return *this;
}

//string�� �ι��ڸ� ������ character�迭�� �ٲ��ִ� �Լ�
const char* String::c_str() const {
	return itsString;//itsString�� �ι��ڸ� �����ϰ� �����Ƿ� itsString�� ��ȯ���ش�.
}
//string�� �ι��ڸ� ������ character�迭�� �ٲ��ִ� �Լ�
const char* String::data() const {
	return itsString;
}

//�迭 s�� string�� pos���� len������ ���ڿ��� �����ϴ� �Լ�
size_t String::copy(char* s, size_t len, size_t pos) const {
	for (int i = 0; i < len; i++)
		s[i] = itsString[pos + i];
	return len;
}

//string���� c���ִ� �ڸ��� �ε����� ��ȯ�ϴ� �Լ�
size_t String::find(char c, size_t pos) const{
	for (unsigned short i = pos; i < itsLen; i++) {
		if (itsString[i] == c){
			return i;
			break;
		}
	}
	return npos;//ã�� ���ڰ� ������ npos�� ��ȯ�Ѵ�.
}
 
//string���� str�� �ִ� ���� �ε����� ��ȯ�ϴ� �Լ�
size_t String::find(const String& str, size_t pos) const {
	if(str.itsLen == 0) return npos;//str�� ���̰� 0�̸� npos�� ��ȯ�Ѵ�.

	for (unsigned short i = pos, j = 0; i < itsLen - str.GetLen(); i++) {//str���ڿ��� ���� ���ڿ��� �ִ��� ã�ƺ� �� ������ �ε����� ��ȯ�Ѵ�.
		while(j != str.GetLen())
			{
				if(itsString[i] != str[j++])
					break;
			}
			if(j == str.GetLen()) return i;
			
			
		}
	return npos;//ã������ ���ڿ��� ã�� �� �� ���, npos�� ��ȯ�Ѵ�.

}

//string���� str�ȿ� �ִ� ��� ���ڶ� ���� ó�� �����ϴ� ���� �ε����� ��ȯ�ϴ� �Լ�
size_t String::find_first_of(const String& str, size_t pos) const {
	for(size_t i = 0; i < itsLen; i++)
	{
		for(size_t j = 0; j < str.GetLen(); j++)
		{
			if(itsString[i] == str[j])
				return i;
		}
	}
	return npos;//ã������ ���ڿ��� ã�� �� �� ���, npos�� ��ȯ�Ѵ�.
}

//string���� str�ȿ� �ִ� ��� ���ڶ� �� �������� �����ϴ� ���� �ε����� ��ȯ�ϴ� �Լ�
size_t String::find_last_of(const String& str, size_t pos) const {
	for(size_t i = itsLen -1; i >= 0; i--)
	{
		for(size_t j = 0; j < str.GetLen(); j++)
		{
			if(itsString[i] == str[j])
				return i;
		}
	}
	return npos;//ã������ ���ڿ��� ã�� �� �� ���, npos�� ��ȯ�Ѵ�.

}

//�ӽð�ü�� string�� �����Ͽ� �����ϴ� �Լ�
String String::substr(size_t pos, size_t len) const {
	String str(len);//substring�� ������ �ӽð�ü�� �����Ѵ�.
	for (int i = 0; i < len; i++) {
		str[i] = itsString[pos+i];
	}//�ӽð�ü�� pos���� ���̰� len�� ���ڿ��� �Է��Ѵ�.
	str[len] = '\0';//�ӽð�ü�� ������ �ε����� �ι��ڸ� �ִ´�.
	return str;//�ӽð�ü�� ��ȯ�Ѵ�.
}

//string�� str�� ���ϴ� �Լ�
int String::compare(const String& str) const {
	if (itsLen > str.length()) return 1;
	else if (itsLen < str.length()) return -1;
	else {
		for (int i = 0; i < itsLen; i++) {
			if (itsString[i] > str[i]) return 1;
			else if (itsString[i] < str[i]) return -1;
		}
		return 0;
	}
}
