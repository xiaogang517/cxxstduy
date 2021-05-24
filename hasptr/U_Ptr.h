class U_Ptr
{
	friend class HasPtr;
	int* m_ip;
	size_t use;
	U_Ptr(int* p);
	~U_Ptr();
};