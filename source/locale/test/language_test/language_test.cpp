/* Test language manager of the Subterranean Rose i18n module */

#include <sr/locale/language.hpp>
#include <cassert>
#include <locale>
#include <boost/locale.hpp>


int main()
{
    using namespace srose;
    using namespace srose::util;

    locale::language en("./locale/en/");
    assert(en.gettext("srose.language.name") == "English");
    assert(en.gettext("@not.found", "You'll get me") == "You'll get me");
    assert(en.gettext("test.sub.hello") == "Greeting from sub-directory!");

    boost::locale::generator gen;
    std::locale::global(gen("zh-CN.UTF-8"));
    locale::language zh_CN("./locale/zh-CN/");
    assert(boost::locale::conv::utf_to_utf<wchar_t>(zh_CN.gettext("srose.language.name")) == L"简体中文");
    assert(zh_CN.gettext("srose.language.name") == "简体中文");

    return EXIT_SUCCESS;
}