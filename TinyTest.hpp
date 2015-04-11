#include <functional>
#include <vector>
#include <iostream>

constexpr bool PASSED = true;
constexpr bool FAILED = false;

#define PASS do{ \
     std::cout << "Test case " << __FUNCTION__  \
     << " PASSED" << std::endl;  \
     return PASSED; }while(0)

#define FAIL do{ \
     std::cout << "Test case " << __FUNCTION__  \
     << " FAILED" << std::endl;  \
     return FAILED; }while(0)

typedef std::function<bool(void)> testCase_t;

class TestRunner
{
  public:
    void runAll()
    {
      for(auto tc : m_testCases)
        tc();
    }
    static TestRunner& inst()
    {
        static TestRunner instance;
        return instance;
    }
    void addTestCase(testCase_t tc)
    {
      m_testCases.push_back(tc);
    }
  private:
    TestRunner() : m_testCases() {}
    std::vector<testCase_t> m_testCases;
};
