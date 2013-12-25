class Singleton{
public:
	static Singleton *getInstance(){
		static Singleton m_instance;
		return &m_instance;
	}
protected:
	Singleton(){};
	Singleton(const Singleton &);
	Singleton& operator=(const Singleton&);
};