#include <assert.h>

#include <iostream>

#include "flycv.h"
#include "gflags/gflags.h"
#include "utils/test_util.h"

using namespace g_fcv_ns;

DEFINE_string(input_file,  "../../bin/" + GRAY_1280X720_U8_BIN, "input image bin file path, generate Mat");
DEFINE_int32(input_width, IMG_720P_WIDTH, "input image width");
DEFINE_int32(input_height, IMG_720P_HEIGHT, "input image height");
DEFINE_string(output_file, "", "output image file path");

int main(int argc, char *argv[]) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    assert(!FLAGS_input_file.empty());

    Mat img_src(FLAGS_input_width, FLAGS_input_height, FCVImageType::GRAY_U8);
    int status =
            read_binary_file(FLAGS_input_file, img_src.data(), img_src.total_byte_size());
    if (status != 0) {
        std::cout << "Failed to read file: " << FLAGS_input_file << std::endl;
        return -1;
    }

    Mat img_dst;

    Mat map_x(FLAGS_input_width, FLAGS_input_height, FCVImageType::GRAY_F32);
    Mat map_y(FLAGS_input_width, FLAGS_input_height, FCVImageType::GRAY_F32);

    for (int i = 0; i < map_x.height(); i++) {
        for (int j = 0; j < map_x.width(); j++) {
            map_x.at<float>(j, i) = static_cast<float>(j) * 0.233333;
            map_y.at<float>(j, i) = static_cast<float>(map_x.height() - i) * 0.933333;
        }
    }

    status = remap(img_src, img_dst, map_x, map_y);
    if (status != 0) {
        std::cout << "Failed to transform" << std::endl;
        return -1;
    }

    if (!FLAGS_output_file.empty()) {
        imwrite(FLAGS_output_file, img_dst);
    }

    return 0;
}
