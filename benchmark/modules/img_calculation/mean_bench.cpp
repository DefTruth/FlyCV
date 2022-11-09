/***************************************************************************
 *
 * Copyright (c) 2022 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
 * @contributor     liuyinghan
 * @created         2022-10-20 10:09
 */

#include "benchmark/benchmark.h"
#include "common/utils.h"
#include "flycv.h"

using namespace g_fcv_ns;

class MeanBench : public benchmark::Fixture {
public:
    void SetUp(const ::benchmark::State& state) {
        feed_num = state.range(0);
        set_thread_num(1);
    }

public:
    int feed_num;
};

BENCHMARK_DEFINE_F(MeanBench, MeanAvg_4K)(benchmark::State& state) {
    Mat src = Mat(4032, 3024, FCVImageType::GRAY_U8);
    construct_data<unsigned char>(src.total_byte_size(), feed_num, src.data());
    
     
    for (auto _state : state) {
        mean(src);
    }
}

BENCHMARK_DEFINE_F(MeanBench, MeanAvg_720p)(benchmark::State& state) {
    Mat src = Mat(1280, 720, FCVImageType::GRAY_U8);
    construct_data<unsigned char>(src.total_byte_size(), feed_num, src.data());
    
     
    for (auto _state : state) {
        mean(src);
    }
}

BENCHMARK_DEFINE_F(MeanBench, MeanAvg_1080p)(benchmark::State& state) {
    Mat src = Mat(1920, 1080, FCVImageType::GRAY_U8);
    construct_data<unsigned char>(src.total_byte_size(), feed_num, src.data());
    
     
    for (auto _state : state) {
        mean(src);
    }
}

BENCHMARK_DEFINE_F(MeanBench, MeanAvg_4K_Mask)(benchmark::State& state) {
    Mat src = Mat(4032, 3024, FCVImageType::GRAY_U8);
    construct_data<unsigned char>(src.total_byte_size(), feed_num, src.data());
    Mat mask = Mat(4032, 3024, FCVImageType::GRAY_U8);
    construct_data<unsigned char>(mask.total_byte_size(), feed_num, mask.data());
     
    for (auto _state : state) {
        mean(src,mask);
    }
}

BENCHMARK_DEFINE_F(MeanBench, MeanAvg_720p_Mask)(benchmark::State& state) {
    Mat src = Mat(1280, 720, FCVImageType::GRAY_U8);
    construct_data<unsigned char>(src.total_byte_size(), feed_num, src.data());
     Mat mask = Mat(1280, 720, FCVImageType::GRAY_U8);
    construct_data<unsigned char>(mask.total_byte_size(), feed_num, mask.data());
     
    for (auto _state : state) {
        mean(src,mask);
    }
}

BENCHMARK_DEFINE_F(MeanBench, MeanAvg_1080p_Mask)(benchmark::State& state) {
    Mat src = Mat(1920, 1080, FCVImageType::GRAY_U8);
    construct_data<unsigned char>(src.total_byte_size(), feed_num, src.data());
     Mat mask = Mat(1920, 1080, FCVImageType::GRAY_U8);
    construct_data<unsigned char>(mask.total_byte_size(), feed_num, mask.data());
     
    for (auto _state : state) {
        mean(src,mask);
    }
}

BENCHMARK_DEFINE_F(MeanBench, MeanAvg_4K_Rect)(benchmark::State& state) {
    Mat src = Mat(4032, 3024, FCVImageType::GRAY_U8);
    construct_data<unsigned char>(src.total_byte_size(), feed_num, src.data());
    Rect rect = Rect(160, 120, 320, 240);
     
    for (auto _state : state) {
        mean(src,rect);
    }
}

BENCHMARK_DEFINE_F(MeanBench, MeanAvg_720p_Rect)(benchmark::State& state) {
    Mat src = Mat(1280, 720, FCVImageType::GRAY_U8);
    construct_data<unsigned char>(src.total_byte_size(), feed_num, src.data());
    Rect rect = Rect(320, 180, 640, 360);
     
    for (auto _state : state) {
        mean(src,rect);
    }
}

BENCHMARK_DEFINE_F(MeanBench, MeanAvg_1080p_Rect)(benchmark::State& state) {
    Mat src = Mat(1920, 1080, FCVImageType::GRAY_U8);
    construct_data<unsigned char>(src.total_byte_size(), feed_num, src.data());
    Rect rect = Rect(320, 180, 640, 360);
     
    for (auto _state : state) {
        mean(src,rect);
    }
}

BENCHMARK_DEFINE_F(MeanBench, Mean_4K_Stddev)(benchmark::State& state) {
    Mat src = Mat(4032, 3024, FCVImageType::GRAY_U8);
    construct_data<unsigned char>(src.total_byte_size(), feed_num, src.data());
    Mat mean;
    Mat stddev;
     
    for (auto _state : state) {
        mean_stddev(src,mean,stddev);
    }
}

BENCHMARK_DEFINE_F(MeanBench, Mean_720p_Stddev)(benchmark::State& state) {
    Mat src = Mat(1280, 720, FCVImageType::GRAY_U8);
    construct_data<unsigned char>(src.total_byte_size(), feed_num, src.data());
    Mat mean;
    Mat stddev;
     
    for (auto _state : state) {
        mean_stddev(src,mean,stddev);
    }
}

BENCHMARK_DEFINE_F(MeanBench, Mean_1080p_Stddev)(benchmark::State& state) {
    Mat src = Mat(1920, 1080, FCVImageType::GRAY_U8);
    construct_data<unsigned char>(src.total_byte_size(), feed_num, src.data());
    Mat mean;
    Mat stddev;
     
    for (auto _state : state) {
        mean_stddev(src,mean,stddev);
    }
}

BENCHMARK_REGISTER_F(MeanBench, MeanAvg_4K)
        ->Unit(benchmark::kMicrosecond)
        ->Iterations(100)
        ->DenseRange(55, 255, 200);

BENCHMARK_REGISTER_F(MeanBench, MeanAvg_720p)
        ->Unit(benchmark::kMicrosecond)
        ->Iterations(100)
        ->DenseRange(55, 255, 200);

BENCHMARK_REGISTER_F(MeanBench, MeanAvg_1080p)
        ->Unit(benchmark::kMicrosecond)
        ->Iterations(100)
        ->DenseRange(55, 255, 200);

BENCHMARK_REGISTER_F(MeanBench, MeanAvg_4K_Mask)
        ->Unit(benchmark::kMicrosecond)
        ->Iterations(100)
        ->DenseRange(55, 255, 200);

BENCHMARK_REGISTER_F(MeanBench, MeanAvg_720p_Mask)
        ->Unit(benchmark::kMicrosecond)
        ->Iterations(100)
        ->DenseRange(55, 255, 200);

BENCHMARK_REGISTER_F(MeanBench, MeanAvg_1080p_Mask)
        ->Unit(benchmark::kMicrosecond)
        ->Iterations(100)
        ->DenseRange(55, 255, 200);

BENCHMARK_REGISTER_F(MeanBench, MeanAvg_4K_Rect)
        ->Unit(benchmark::kMicrosecond)
        ->Iterations(100)
        ->DenseRange(55, 255, 200);

BENCHMARK_REGISTER_F(MeanBench, MeanAvg_720p_Rect)
        ->Unit(benchmark::kMicrosecond)
        ->Iterations(100)
        ->DenseRange(55, 255, 200);

BENCHMARK_REGISTER_F(MeanBench, MeanAvg_1080p_Rect)
        ->Unit(benchmark::kMicrosecond)
        ->Iterations(100)
        ->DenseRange(55, 255, 200);

BENCHMARK_REGISTER_F(MeanBench, Mean_4K_Stddev)
        ->Unit(benchmark::kMicrosecond)
        ->Iterations(100)
        ->DenseRange(55, 255, 200);

BENCHMARK_REGISTER_F(MeanBench, Mean_720p_Stddev)
        ->Unit(benchmark::kMicrosecond)
        ->Iterations(100)
        ->DenseRange(55, 255, 200);

BENCHMARK_REGISTER_F(MeanBench, Mean_1080p_Stddev)
        ->Unit(benchmark::kMicrosecond)
        ->Iterations(100)
        ->DenseRange(55, 255, 200);