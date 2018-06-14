// [리스트 11.12] 문자열 클래스 사용하기
////////////////////
//Homework by team
//
//Member functions of String class

// 0바이트의 문자열 생성하는 기본 생성자
#include "String.h"
String::String()
{
	itsString = new char[1];
	itsString[0] = '\0';
	itsLen = 0;
}

// 전용(helper) 생성자
// 필요한 만큼의 길이의 문자열을 만드는
// 클래스 메쏘드에 의해서만 사용됨
String::String(unsigned short len)
{
	itsString = new char[len + 1];
	for (unsigned short i = 0; i <= len; i++)
		itsString[i] = '\0';
	itsLen = len;
}

// 문자 배열을 문자열로 변환함 
String::String(const char * const cString)
{
	itsLen = strlen(cString);
	size_t length = 0;
	itsString = new char[itsLen + 1];
	for (unsigned short i = 0; i<itsLen; i++)
		itsString[i] = cString[i];
	itsString[itsLen] = '\0';
}

// 복사 생성자
String::String(const String & rhs)
{
	itsLen = rhs.GetLen();
	itsString = new char[itsLen + 1];
	for (unsigned short i = 0; i<itsLen; i++)
		itsString[i] = rhs[i];
	itsString[itsLen] = '\0';
}
//인덱스 pos부터 길이length만큼 복사하는 복사 생성자
String::String(const String& str, size_t pos, size_t length)
{
	itsLen = length;
	itsString = new char[itsLen + 1];
	for(size_t i = 0; i < itsLen; i++)
		itsString[i] = str[pos + i];
	itsString [itsLen] = '\0';
}
//str배열을 저장하는 length 길이만큼 생성자
String::String(const char* str, size_t length)
{
	itsLen = length;
	itsString = new char[itsLen + 1];
	for(unsigned short i = 0; i < itsLen; i++)
		itsString[i] = str[i];
	itsString[itsLen] = '\0';
}
//n개의 문자c를 저장하는 생성자
String::String(size_t n, char c)
{
	itsLen = n;
	itsString = new char[itsLen + 1];
	for(unsigned short i = 0; i < itsLen; i++)
		itsString[i] = c;
	itsString[itsLen] = '\0';
}
// 소멸자, 메모리 방출함
String::~String()
{
	delete[] itsString;
	itsLen = 0;
}

// 대입 연산자, 기존 메모리 방출함 
// 그리고 문자열과 길이를 복사 
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

// 비상수 변위 연산자 
// 문자의 참조자 반환하여
// 나중에 바꿀 수 있게 함 
char & String::operator[](unsigned short offset)
{
	if (offset > itsLen)
		return itsString[itsLen - 1];
	else
		return itsString[offset];
}

// 상수 객체에 사용되는 
// 상수 변위 연산자 
char String::operator[](unsigned short offset) const
{
	if (offset > itsLen)
		return itsString[itsLen - 1];
	else
		return itsString[offset];
}

// 현재의 문자열에 rhs를 추가하여 
// 새로운 문자열을 만듦
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

// 반환이 없는 현재의 문자열 바꿈 
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
// Implement member functions here!!!(생성자는 위에 작성했습니다!)

//객체의 itsString의 size를 구해주는 함수
size_t String::size() {
	size_t size = 0;
	while (itsString[size] != NULL)
		size++;
	return size;
}
//객체의 itsString의 길이를 구해주는 함수
size_t String::length()const {
	size_t length = 0;
	while (itsString[length] != NULL)
		length++;
	return length;
}
//객체의 itsString을 비워주는 함수
void String::clear() {
	delete [] itsString; // 기존에 가지고있던 문자배열 메모리 해제
	itsString = new char[1]; // 새로운 동적메모리 할당
	itsString[0] = '\0'; // 새로운 문자배열 초기화
	itsLen = 0;
}
//객체의 itsString이 비어있는지 확인해주는 함수
bool String::empty() {
		if (itsString[0] = '\0')//배열의 0번째 인덱스의 값이 널값이면 0을 반환하고, 아니면 1을 반환한다.
			return 0;
	return 1;
}
//객체의 itsString의 인덱스 pos의 값을 반환하는 함수
char& String::at(size_t pos) {
	if(pos>=0 && pos<itsLen)
		return this-> itsString[pos];  // pos의 값이 0보다 크거나 같고 itsLen보다 작을 때 그 pos위치의 값을 반환한다. 
	else
		return this-> itsString[itsLen]; // pos의 값이 if의 조건에 해당하지 않으면 널문자를 반환한다. 
}
//객체의 itsString의 마지막 인덱스의 값을 반환하는 함수
char& String::back() {
	return itsString[itsLen - 1];
}
//객체의 itsString의 0번째 인덱스의 값을 반환하는 함수
char& String::front() {
	return itsString[0];
}

//string과 string을 합치는 함수
String& String::append(const String& str) {
	unsigned short i, totalLen = itsLen + str.GetLen();
	char *temp = new char[itsLen]; // 동적 메모리를 할당하여 기존 문자열을 temp 에 저장한다.
	for (unsigned short j = 0; j < itsLen; j++) {
		temp[j] = itsString[j]; // 기존의 문자배열을 할당받은 메모리에 복사함
	}
	delete[] itsString; // 기존 문자배열 동적메모리를 해제함

	itsString = new char[totalLen+1]; // 기존의 문자배열과 인수로 받은 문자배열을 넣을 동적메모리를 할당받음
	for (i = 0; i < itsLen; i++) {
		itsString[i] = temp[i]; // 기존 문자배열을 복사함
	}
	for (unsigned short j = 0; j < str.GetLen(); i++, j++) {
		itsString[i] = str[j]; // 인수로 받은 문자배열을 복사함
	}
	itsString[totalLen] = '\0'; // 마지막 인덱스에 널문자 삽입
	itsLen = totalLen; // itsLen을 두 문자배열을 합친 길이로 재설정
	delete temp; // 기존의 문자배열을 복사해놓기 위해 할당받았던 동적메모리를 해제함
	return *this;
}

//string의 pos자리에 다른 string을 삽입하는 함수
String& String::insert(size_t pos, const String& str)
{
	unsigned short i, totalLen = itsLen + str.GetLen();
	char *temp = new char[itsLen]; // 기존 문자배열을 복사해놓기 위해 동적메모리를 할당받음
	for (unsigned short j = 0; j < itsLen; j++) {
		temp[j] = itsString[j]; // 기존의 문자배열을 할당받은 메모리에 복사함
	}
	delete[] itsString; // 기존 문자배열의 메모리를 해제함

	itsString = new char[totalLen+1]; // 기존의 문자배열과 인수로 받은 문자배열을 넣을 동적메모리를 할당받음
	for (i = 0; i < pos; i++) { 
		itsString[i] = temp[i]; // pos인덱스 전까지는 기존 문자배열을 그대로 복사함
	}
	for (unsigned short j = 0; j < str.GetLen(); i++, j++) { 
		itsString[i] = str[j]; // pos인덱스부터 인수로 받은 문자배열을 복사함
	}
	for (unsigned short k = pos; k < itsLen; i++, k++) { 
		itsString[i] = temp[k]; // 기존 문자배열의 pos인덱스 이후의 문자배열을 복사함
	}
	itsString[totalLen] = '\0'; // 마지막 인덱스에 널문자 삽입
	itsLen = totalLen; // itsLen을 두 문자배열을 합친 길이로 재설정
	delete [] temp; // 기존의 문자배열을 복사해놓기 위해 할당받았던 동적메모리를 해제함
	return *this; 
}

//string의 pos자리부터 len길이만큼 지우는 함수
String& String::erase (size_t pos, size_t len){
	size_t i, totalLen = itsLen - len; // totalLen을 원래 길이인 itsLen에서 삭제할 길이인 len을 뺀 값으로 설정한다.
	size_t finish_Erase = pos + len;  // 삭제가 종료되는 지점은 첫 번째 문자의 위치에 삭제할 문자의 수를 더한 값이다. 
	
    char *temp = new char [totalLen+1];
    
    for(i=0; i<pos; i++)
	{
		temp[i] = itsString[i]; 
		// 새로운 객체 temp에 삭제할 위치 전까지의 문자열을 옮겨준다. 
	}
	
	for(i = pos ; i < totalLen; i++,finish_Erase++)
	{     
		temp[i] = itsString[finish_Erase]; 
		// itsString에 있는 나머지 문자열들을 temp에 넣어준다. 
	}
	
    delete[] itsString;  // itsString에 있는 메모리를 해제한다.

    itsString = new char [totalLen+1]; // itsString에 다시 메모리를 totalLen+1만큼 할당해준다. 
    
   	for(i=0; i<totalLen; i++)
	{
    	itsString[i] = temp[i];  // itsString에 temp를 복사 해준다. 
    }
	itsString[totalLen] = '\0'; 	// itsString 문자열 끝에 널문자를 넣어준다. 

    delete[] temp; 	
	return *this;
}

//string의 pos자리부터 len길이만큼 str로 대체하는 함수
String& String::replace(size_t pos, size_t len, const String& str) {
	char * temp = new char [itsLen + 1];//대체할 배열을 저장하기 위해 동적으로 메모리를 할당한다.

	for (size_t i = 0; i < pos; i++)//0부터 pos-1 인덱스에는 itsString배열의 값을 저장한다.
		temp[i] = itsString[i];
	for (size_t i = pos; i < pos + len; i++)//pos부터 (pos + len -1)인덱스에는 str배열의 값을 저장한다.
		temp[i] = str[i - pos];
	for (size_t i = pos + len; i < itsLen; i++)//(pos + itsLen - 1)인데스에는 itsString배열의 값을 저장한다.
		temp[i] = itsString[i];
	delete [] itsString;//itsString의 메모리를 해제한다.

	itsString = new char[itsLen + 1];//대체된 배열을 다시 저장하기 위해 메모리를 동적으로 할당한다.

	for(size_t i = 0; i < itsLen; i++)//temp배열을 itsString에 복사한다.
		itsString[i] = temp[i];

	delete [] temp;//임시배열의 메모리를 해제한다.
	return *this;
}

// 두 문자열을 swap하는 함수
void String::swap(String& str) {
   size_t i;
   int len = 0;
   // itsString의 길이와 인자로받은 str의 길이중 더 긴 것을 정수 변수 len에 넣는다.
   if (itsLen > str.GetLen())
      len = itsLen;
   else
      len = str.GetLen();
   // 임시 배열 생성
   char* tmp = new char[len + 1];
   // itsString에 있는 문자들을 tmp 배열로 옮긴다.
   for (i = 0; i < len; i++)
      tmp[i] = itsString[i];
   tmp[len] = '\0';
   // 기존에 있던 itsString을 삭제하고 길이가 len+1인 배열로 다시 선언한다.
   delete[] itsString;
   itsString = new char[len + 1];
   // str에 있는 문자들을 itsString으로 옮긴다.
   for (i = 0; i < len; i++)
      itsString[i] = str[i];
   itsString[len] = '\0';
   // 임시 배열 tmp에 있는, 즉 원래 itsString에 있던 문자들을 str로 옮긴다.
   for (i = 0; i < len; i++)
      str[i] = tmp[i];
   str[len] = '\0';
   // 임시 배열 tmp를 삭제한다.
   delete[] tmp;
}

//string에 있는 대문자를 소문자로 바꾸는 함수
String& String::lower() {
	for(size_t i = 0; i < itsLen; i++)
	{
		if(itsString[i] >= 'A' &&itsString[i] <= 'Z')
			itsString[i] += 'a' - 'A';
	}
	return *this;
}


//string에 있는 소문자를 대문자로 바꾸는 함수
String& String::upper() {
	for(size_t i = 0; i < itsLen; i++)
	{
		if(itsString[i] >= 'a' &&itsString[i] <= 'z')
			itsString[i] -= 'a' - 'A';
	}
	return *this;
}

//string을 널문자를 포함한 character배열로 바꿔주는 함수
const char* String::c_str() const {
	return itsString;//itsString이 널문자를 포함하고 있으므로 itsString을 반환해준다.
}
//string을 널문자를 포함한 character배열로 바꿔주는 함수
const char* String::data() const {
	return itsString;
}

//배열 s에 string의 pos부터 len길이의 문자열을 복사하는 함수
size_t String::copy(char* s, size_t len, size_t pos) const {
	for (int i = 0; i < len; i++)
		s[i] = itsString[pos + i];
	return len;
}

//string에서 c가있는 자리의 인덱스를 반환하는 함수
size_t String::find(char c, size_t pos) const{
	for (unsigned short i = pos; i < itsLen; i++) {
		if (itsString[i] == c){
			return i;
			break;
		}
	}
	return npos;//찾는 문자가 없으면 npos를 반환한다.
}
 
//string에서 str이 있는 곳의 인덱스를 반환하는 함수
size_t String::find(const String& str, size_t pos) const {
	if(str.itsLen == 0) return npos;//str의 길이가 0이면 npos를 반환한다.

	for (unsigned short i = pos, j = 0; i < itsLen - str.GetLen(); i++) {//str문자열과 같은 문자열이 있는지 찾아본 후 있으면 인덱스를 반환한다.
		while(j != str.GetLen())
			{
				if(itsString[i] != str[j++])
					break;
			}
			if(j == str.GetLen()) return i;
			
			
		}
	return npos;//찾으려는 문자열을 찾지 못 한 경우, npos를 반환한다.

}

//string에서 str안에 있는 어떠한 문자라도 제일 처음 출현하는 곳의 인덱스를 반환하는 함수
size_t String::find_first_of(const String& str, size_t pos) const {
	for(size_t i = 0; i < itsLen; i++)
	{
		for(size_t j = 0; j < str.GetLen(); j++)
		{
			if(itsString[i] == str[j])
				return i;
		}
	}
	return npos;//찾으려는 문자열을 찾지 못 한 경우, npos를 반환한다.
}

//string에서 str안에 있는 어떠한 문자라도 맨 마지막에 출현하는 곳의 인덱스를 반환하는 함수
size_t String::find_last_of(const String& str, size_t pos) const {
	for(size_t i = itsLen -1; i >= 0; i--)
	{
		for(size_t j = 0; j < str.GetLen(); j++)
		{
			if(itsString[i] == str[j])
				return i;
		}
	}
	return npos;//찾으려는 문자열을 찾지 못 한 경우, npos를 반환한다.

}

//임시객체에 string을 복사하여 저장하는 함수
String String::substr(size_t pos, size_t len) const {
	String str(len);//substring을 저장할 임시객체를 생성한다.
	for (int i = 0; i < len; i++) {
		str[i] = itsString[pos+i];
	}//임시객체에 pos부터 길이가 len인 문자열을 입력한다.
	str[len] = '\0';//임시객체의 마지막 인덱스에 널문자를 넣는다.
	return str;//임시객체를 반환한다.
}

//string과 str을 비교하는 함수
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
