        #include <cmrc/cmrc.hpp>
#include <map>
#include <utility>

namespace cmrc {
namespace StaringContest-resources {

namespace res_chars {
// These are the files which are available in this resource library
// Pointers to res/cascade_eye.xml
extern const char* const f_d321_res_cascade_eye_xml_begin;
extern const char* const f_d321_res_cascade_eye_xml_end;
// Pointers to res/highscore.dat
extern const char* const f_1c41_res_highscore_dat_begin;
extern const char* const f_1c41_res_highscore_dat_end;
// Pointers to NotoSansJP-Medium.otf
extern const char* const f_fa5a_NotoSansJP_Medium_otf_begin;
extern const char* const f_fa5a_NotoSansJP_Medium_otf_end;
}

namespace {

const cmrc::detail::index_type&
get_root_index() {
    static cmrc::detail::directory root_directory_;
    static cmrc::detail::file_or_directory root_directory_fod{root_directory_};
    static cmrc::detail::index_type root_index;
    root_index.emplace("", &root_directory_fod);
    struct dir_inl {
        class cmrc::detail::directory& directory;
    };
    dir_inl root_directory_dir{root_directory_};
    (void)root_directory_dir;
    static auto f_9b20_res_dir = root_directory_dir.directory.add_subdir("res");
    root_index.emplace("res", &f_9b20_res_dir.index_entry);
    root_index.emplace(
        "res/cascade_eye.xml",
        f_9b20_res_dir.directory.add_file(
            "cascade_eye.xml",
            res_chars::f_d321_res_cascade_eye_xml_begin,
            res_chars::f_d321_res_cascade_eye_xml_end
        )
    );
    root_index.emplace(
        "res/highscore.dat",
        f_9b20_res_dir.directory.add_file(
            "highscore.dat",
            res_chars::f_1c41_res_highscore_dat_begin,
            res_chars::f_1c41_res_highscore_dat_end
        )
    );
    root_index.emplace(
        "NotoSansJP-Medium.otf",
        root_directory_dir.directory.add_file(
            "NotoSansJP-Medium.otf",
            res_chars::f_fa5a_NotoSansJP_Medium_otf_begin,
            res_chars::f_fa5a_NotoSansJP_Medium_otf_end
        )
    );
    return root_index;
}

}

cmrc::embedded_filesystem get_filesystem() {
    static auto& index = get_root_index();
    return cmrc::embedded_filesystem{index};
}

} // StaringContest-resources
} // cmrc
    