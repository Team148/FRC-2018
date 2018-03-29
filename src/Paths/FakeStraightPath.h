#ifndef FakeStraightPath_H
#define FakeStraightPath_H

#include "TrajectoryPath.h"

class FakeStraightPath : public TrajectoryPath {
public:

	static TrajectoryPath* GetInstance();

	int GetIndexLength();
	double GetInitialHeading();
	double GetEndHeading();
	double GetTimeLength();
	double* GetLeftTrajectoryArray(int index);
	double* GetRightTrajectoryArray(int index);
	double GetLeftPosition(int index);
	double GetLeftVelocity(int index);
	double GetLeftAcceleration(int index);
	double GetRightPosition(int index);
	double GetRightVelocity(int index);
	double GetRightAcceleration(int index);
	double GetHeading(int index);


private:
	FakeStraightPath();
	static FakeStraightPath *m_instance;

	int num_index = 244;
	double left_wheel[244][8] ={
	{0.000, 0.059, 5.858, 585.768, 0.000, 0.010, 0.000, 12.450},
	{0.001, 0.117, 5.858, -0.017, 0.000, 0.010, 0.001, 12.450},
	{0.004, 0.264, 14.643, 878.563, 0.000, 0.010, 0.004, 12.450},
	{0.009, 0.469, 20.498, 585.490, 0.000, 0.010, 0.009, 12.450},
	{0.016, 0.732, 26.349, 585.129, 0.000, 0.010, 0.016, 12.450},
	{0.027, 1.054, 32.195, 584.538, 0.000, 0.010, 0.027, 12.450},
	{0.041, 1.434, 38.031, 583.660, 0.000, 0.010, 0.041, 12.450},
	{0.060, 1.873, 43.856, 582.439, 0.000, 0.010, 0.060, 12.450},
	{0.083, 2.370, 49.664, 580.820, 0.000, 0.010, 0.083, 12.450},
	{0.113, 2.924, 55.451, 578.747, 0.000, 0.010, 0.113, 12.450},
	{0.148, 3.536, 61.213, 576.167, 0.000, 0.010, 0.148, 12.450},
	{0.190, 4.206, 66.943, 573.029, 0.000, 0.010, 0.190, 12.450},
	{0.239, 4.932, 72.636, 569.282, 0.000, 0.010, 0.239, 12.450},
	{0.297, 5.715, 78.285, 564.879, 0.000, 0.010, 0.297, 12.450},
	{0.362, 6.554, 83.883, 559.775, 0.000, 0.010, 0.362, 12.450},
	{0.437, 7.448, 89.422, 553.927, 0.000, 0.010, 0.437, 12.450},
	{0.521, 8.397, 94.895, 547.297, 0.000, 0.010, 0.521, 12.450},
	{0.614, 9.371, 97.395, 249.960, 0.000, 0.010, 0.614, 12.450},
	{0.718, 10.340, 96.937, -45.717, 0.000, 0.010, 0.718, 12.450},
	{0.831, 11.304, 96.435, -50.197, 0.000, 0.010, 0.831, 12.450},
	{0.953, 12.263, 95.890, -54.588, 0.001, 0.010, 0.953, 12.450},
	{1.085, 13.216, 95.301, -58.887, 0.001, 0.010, 1.085, 12.450},
	{1.227, 14.163, 94.670, -63.089, 0.001, 0.010, 1.227, 12.450},
	{1.378, 15.103, 93.998, -67.196, 0.001, 0.010, 1.378, 12.451},
	{1.538, 16.036, 93.286, -71.204, 0.002, 0.010, 1.538, 12.451},
	{1.708, 16.961, 92.535, -75.117, 0.002, 0.010, 1.708, 12.451},
	{1.887, 17.879, 91.745, -78.936, 0.002, 0.010, 1.887, 12.452},
	{2.075, 18.788, 90.919, -82.663, 0.003, 0.010, 2.075, 12.452},
	{2.272, 19.688, 90.056, -86.303, 0.004, 0.010, 2.272, 12.453},
	{2.477, 20.580, 89.157, -89.862, 0.004, 0.010, 2.477, 12.453},
	{2.692, 21.462, 88.223, -93.344, 0.005, 0.010, 2.692, 12.454},
	{2.915, 22.335, 87.256, -96.759, 0.006, 0.010, 2.915, 12.456},
	{3.147, 23.197, 86.255, -100.111, 0.007, 0.010, 3.147, 12.457},
	{3.388, 24.050, 85.221, -103.410, 0.008, 0.010, 3.388, 12.459},
	{3.637, 24.891, 84.154, -106.664, 0.009, 0.010, 3.637, 12.461},
	{3.894, 25.722, 83.055, -109.882, 0.010, 0.010, 3.894, 12.463},
	{4.159, 26.541, 81.925, -113.072, 0.012, 0.010, 4.159, 12.466},
	{4.433, 27.349, 80.762, -116.242, 0.013, 0.010, 4.433, 12.470},
	{4.714, 28.144, 79.568, -119.402, 0.015, 0.010, 4.714, 12.474},
	{5.004, 28.928, 78.343, -122.555, 0.017, 0.010, 5.003, 12.479},
	{5.301, 29.698, 77.085, -125.713, 0.019, 0.010, 5.300, 12.484},
	{5.605, 30.456, 75.797, -128.875, 0.022, 0.010, 5.605, 12.490},
	{5.917, 31.201, 74.476, -132.047, 0.024, 0.010, 5.917, 12.497},
	{6.237, 31.932, 73.124, -135.229, 0.027, 0.010, 6.236, 12.506},
	{6.563, 32.650, 71.740, -138.419, 0.030, 0.010, 6.562, 12.515},
	{6.897, 33.353, 70.324, -141.612, 0.033, 0.010, 6.896, 12.525},
	{7.237, 34.042, 68.876, -144.799, 0.037, 0.010, 7.236, 12.537},
	{7.584, 34.716, 67.396, -147.966, 0.040, 0.010, 7.583, 12.551},
	{7.938, 35.375, 65.885, -151.097, 0.044, 0.010, 7.936, 12.565},
	{8.298, 36.018, 64.343, -154.166, 0.049, 0.010, 8.296, 12.582},
	{8.665, 36.646, 62.772, -157.141, 0.053, 0.010, 8.662, 12.601},
	{9.037, 37.258, 61.172, -159.984, 0.058, 0.010, 9.034, 12.621},
	{9.416, 37.853, 59.546, -162.648, 0.063, 0.010, 9.412, 12.644},
	{9.800, 38.432, 57.895, -165.078, 0.069, 0.010, 9.795, 12.670},
	{10.190, 38.994, 56.223, -167.200, 0.075, 0.010, 10.184, 12.698},
	{10.585, 39.539, 54.533, -168.942, 0.081, 0.010, 10.579, 12.728},
	{10.986, 40.068, 52.831, -170.202, 0.087, 0.010, 10.978, 12.762},
	{11.392, 40.579, 51.123, -170.877, 0.094, 0.010, 11.382, 12.799},
	{11.802, 41.073, 49.414, -170.842, 0.102, 0.010, 11.791, 12.839},
	{12.218, 41.550, 47.715, -169.955, 0.110, 0.010, 12.204, 12.883},
	{12.638, 42.011, 46.034, -168.063, 0.118, 0.010, 12.621, 12.930},
	{13.063, 42.454, 44.384, -164.983, 0.127, 0.010, 13.043, 12.982},
	{13.491, 42.882, 42.779, -160.526, 0.136, 0.010, 13.468, 13.038},
	{13.924, 43.295, 41.234, -154.484, 0.145, 0.010, 13.897, 13.099},
	{14.361, 43.692, 39.768, -146.621, 0.155, 0.010, 14.329, 13.164},
	{14.802, 44.076, 38.401, -136.709, 0.166, 0.010, 14.764, 13.235},
	{15.247, 44.448, 37.156, -124.489, 0.177, 0.010, 15.202, 13.311},
	{15.695, 44.808, 36.059, -109.711, 0.189, 0.010, 15.642, 13.392},
	{16.146, 45.160, 35.137, -92.127, 0.201, 0.010, 16.085, 13.480},
	{16.601, 45.504, 34.423, -71.489, 0.213, 0.010, 16.531, 13.573},
	{17.060, 45.844, 33.947, -47.587, 0.227, 0.010, 16.978, 13.673},
	{17.522, 46.181, 33.744, -20.235, 0.240, 0.010, 17.427, 13.780},
	{17.987, 46.519, 33.851, 10.701, 0.255, 0.010, 17.878, 13.894},
	{18.455, 46.863, 34.304, 45.290, 0.269, 0.010, 18.331, 14.015},
	{18.927, 47.214, 35.139, 83.509, 0.285, 0.010, 18.785, 14.144},
	{19.403, 47.578, 36.392, 125.251, 0.300, 0.010, 19.241, 14.281},
	{19.883, 47.959, 38.095, 170.269, 0.317, 0.010, 19.698, 14.427},
	{20.366, 48.362, 40.277, 218.207, 0.333, 0.010, 20.156, 14.581},
	{20.854, 48.791, 42.962, 268.548, 0.351, 0.010, 20.616, 14.745},
	{21.347, 49.253, 46.168, 320.633, 0.368, 0.010, 21.077, 14.918},
	{21.844, 49.752, 49.905, 373.663, 0.386, 0.010, 21.539, 15.102},
	{22.347, 50.294, 54.172, 426.696, 0.405, 0.010, 22.003, 15.295},
	{22.856, 50.883, 58.959, 478.682, 0.423, 0.010, 22.469, 15.500},
	{23.371, 51.526, 64.244, 528.492, 0.442, 0.010, 22.937, 15.716},
	{23.894, 52.226, 69.993, 574.952, 0.462, 0.010, 23.407, 15.944},
	{24.424, 52.987, 76.162, 616.901, 0.481, 0.010, 23.879, 16.185},
	{24.962, 53.814, 82.695, 653.242, 0.501, 0.010, 24.353, 16.438},
	{25.509, 54.709, 89.525, 682.997, 0.520, 0.010, 24.831, 16.706},
	{26.066, 55.675, 96.578, 705.360, 0.540, 0.010, 25.311, 16.987},
	{26.633, 56.713, 103.776, 719.748, 0.559, 0.010, 25.795, 17.283},
	{27.211, 57.823, 111.034, 725.831, 0.579, 0.010, 26.282, 17.595},
	{27.801, 59.006, 118.270, 723.553, 0.598, 0.010, 26.773, 17.923},
	{28.404, 60.260, 125.401, 713.140, 0.618, 0.010, 27.267, 18.267},
	{29.019, 61.583, 132.352, 695.084, 0.637, 0.010, 27.766, 18.628},
	{29.649, 62.974, 139.053, 670.114, 0.655, 0.010, 28.269, 19.007},
	{30.293, 64.428, 145.445, 639.161, 0.673, 0.010, 28.776, 19.405},
	{30.953, 65.943, 151.478, 603.296, 0.691, 0.010, 29.288, 19.820},
	{31.628, 67.514, 157.114, 563.692, 0.709, 0.010, 29.804, 20.255},
	{32.319, 69.138, 162.330, 521.552, 0.725, 0.010, 30.325, 20.710},
	{33.027, 70.809, 167.111, 478.073, 0.742, 0.010, 30.851, 21.184},
	{33.753, 72.523, 171.455, 434.383, 0.757, 0.010, 31.382, 21.678},
	{34.495, 74.277, 175.370, 391.526, 0.773, 0.010, 31.918, 22.192},
	{35.256, 76.066, 178.874, 350.416, 0.787, 0.010, 32.459, 22.727},
	{36.035, 77.886, 181.992, 311.845, 0.801, 0.010, 33.005, 23.283},
	{36.832, 79.733, 184.757, 276.444, 0.814, 0.010, 33.556, 23.859},
	{37.648, 81.581, 184.727, -3.021, 0.826, 0.010, 34.112, 24.456},
	{38.482, 83.398, 181.785, -294.198, 0.838, 0.010, 34.673, 25.072},
	{39.334, 85.182, 178.358, -342.637, 0.849, 0.010, 35.240, 25.709},
	{40.203, 86.927, 174.496, -386.244, 0.859, 0.010, 35.811, 26.364},
	{41.090, 88.629, 170.248, -424.829, 0.869, 0.010, 36.386, 27.038},
	{41.992, 90.286, 165.664, -458.366, 0.877, 0.010, 36.966, 27.730},
	{42.911, 91.894, 160.794, -486.975, 0.885, 0.010, 37.551, 28.439},
	{43.846, 93.451, 155.685, -510.878, 0.892, 0.010, 38.140, 29.165},
	{44.795, 94.955, 150.381, -530.391, 0.898, 0.010, 38.733, 29.906},
	{45.759, 96.404, 144.923, -545.889, 0.904, 0.010, 39.332, 30.662},
	{46.737, 97.797, 139.345, -557.786, 0.908, 0.010, 39.935, 31.431},
	{47.729, 99.134, 133.679, -566.533, 0.912, 0.010, 40.543, 32.214},
	{48.733, 100.414, 127.953, -572.591, 0.915, 0.010, 41.157, 33.009},
	{49.749, 101.636, 122.189, -576.431, 0.917, 0.010, 41.775, 33.815},
	{50.777, 102.800, 116.404, -578.525, 0.919, 0.010, 42.400, 34.632},
	{51.816, 103.906, 110.610, -579.349, 0.919, 0.010, 43.030, 35.458},
	{52.866, 104.931, 102.531, -807.959, 0.919, 0.010, 43.667, 36.292},
	{53.924, 105.875, 94.366, -816.505, 0.918, 0.010, 44.310, 37.133},
	{54.992, 106.759, 88.443, -592.249, 0.916, 0.010, 44.959, 37.981},
	{56.068, 107.584, 82.515, -592.852, 0.913, 0.010, 45.616, 38.833},
	{57.151, 108.350, 76.569, -594.620, 0.909, 0.010, 46.280, 39.689},
	{58.242, 109.056, 70.588, -598.023, 0.905, 0.010, 46.952, 40.548},
	{59.339, 109.701, 64.553, -603.536, 0.900, 0.010, 47.632, 41.409},
	{60.442, 110.286, 58.437, -611.633, 0.894, 0.010, 48.320, 42.271},
	{61.550, 110.808, 52.209, -622.774, 0.887, 0.010, 49.017, 43.132},
	{62.662, 111.266, 45.835, -637.413, 0.879, 0.010, 49.724, 43.992},
	{63.779, 111.659, 39.275, -655.972, 0.871, 0.010, 50.439, 44.849},
	{64.899, 111.984, 32.487, -678.845, 0.861, 0.010, 51.165, 45.702},
	{66.021, 112.238, 25.423, -706.348, 0.851, 0.010, 51.900, 46.550},
	{67.145, 112.418, 18.036, -738.738, 0.841, 0.010, 52.645, 47.392},
	{68.271, 112.521, 10.274, -776.158, 0.829, 0.010, 53.400, 48.226},
	{69.396, 112.542, 2.088, -818.612, 0.817, 0.010, 54.166, 49.051},
	{70.521, 112.476, -6.571, -865.955, 0.804, 0.010, 54.941, 49.866},
	{71.644, 112.346, -13.067, -649.541, 0.790, 0.010, 55.726, 50.670},
	{72.766, 112.180, -16.526, -345.913, 0.776, 0.010, 56.521, 51.461},
	{73.886, 111.985, -19.561, -303.483, 0.761, 0.010, 57.326, 52.239},
	{75.003, 111.755, -22.975, -341.370, 0.745, 0.010, 58.141, 53.004},
	{76.118, 111.487, -26.794, -381.948, 0.729, 0.010, 58.966, 53.753},
	{77.230, 111.177, -31.039, -424.467, 0.712, 0.010, 59.802, 54.487},
	{78.338, 110.819, -35.719, -468.035, 0.695, 0.010, 60.647, 55.204},
	{79.442, 110.411, -40.835, -511.643, 0.677, 0.010, 61.501, 55.904},
	{80.542, 109.947, -46.377, -554.170, 0.659, 0.010, 62.363, 56.585},
	{81.636, 109.424, -52.322, -594.443, 0.641, 0.010, 63.235, 57.248},
	{82.724, 108.838, -58.634, -631.245, 0.622, 0.010, 64.113, 57.890},
	{83.806, 108.185, -65.268, -663.401, 0.603, 0.010, 64.998, 58.512},
	{84.881, 107.463, -72.166, -689.810, 0.583, 0.010, 65.889, 59.113},
	{85.948, 106.671, -79.261, -709.504, 0.564, 0.010, 66.785, 59.692},
	{87.006, 105.806, -86.478, -721.701, 0.544, 0.010, 67.685, 60.248},
	{88.054, 104.869, -93.737, -725.860, 0.525, 0.010, 68.587, 60.783},
	{89.093, 103.859, -100.954, -721.686, 0.505, 0.010, 69.491, 61.294},
	{90.121, 102.779, -108.045, -709.176, 0.485, 0.010, 70.396, 61.782},
	{91.137, 101.629, -114.931, -688.593, 0.466, 0.010, 71.299, 62.248},
	{92.141, 100.414, -121.536, -660.469, 0.447, 0.010, 72.201, 62.690},
	{93.133, 99.136, -127.792, -625.561, 0.428, 0.010, 73.099, 63.110},
	{94.111, 97.800, -133.640, -584.812, 0.409, 0.010, 73.992, 63.507},
	{95.075, 96.409, -139.033, -539.295, 0.390, 0.010, 74.881, 63.882},
	{96.024, 94.970, -143.934, -490.162, 0.372, 0.010, 75.762, 64.236},
	{96.959, 93.487, -148.320, -438.590, 0.355, 0.010, 76.636, 64.568},
	{97.879, 91.965, -152.177, -385.714, 0.337, 0.010, 77.501, 64.880},
	{98.783, 90.410, -155.504, -332.619, 0.320, 0.010, 78.357, 65.172},
	{99.671, 88.827, -158.306, -280.256, 0.304, 0.010, 79.202, 65.444},
	{100.543, 87.221, -160.601, -229.468, 0.288, 0.010, 80.036, 65.699},
	{101.399, 85.597, -162.410, -180.949, 0.273, 0.010, 80.859, 65.936},
	{102.239, 83.959, -163.763, -135.237, 0.258, 0.010, 81.669, 66.156},
	{103.062, 82.312, -164.690, -92.738, 0.244, 0.010, 82.467, 66.360},
	{103.869, 80.660, -165.227, -53.705, 0.230, 0.010, 83.251, 66.549},
	{104.659, 79.006, -165.410, -18.294, 0.216, 0.010, 84.021, 66.724},
	{105.432, 77.353, -165.275, 13.464, 0.204, 0.010, 84.778, 66.885},
	{106.189, 75.705, -164.859, 41.622, 0.191, 0.010, 85.520, 67.034},
	{106.930, 74.063, -164.196, 66.292, 0.180, 0.010, 86.248, 67.170},
	{107.654, 72.429, -163.320, 87.653, 0.168, 0.010, 86.961, 67.296},
	{108.362, 70.807, -162.261, 105.909, 0.158, 0.010, 87.660, 67.411},
	{109.054, 69.196, -161.048, 121.310, 0.148, 0.010, 88.344, 67.516},
	{109.730, 67.599, -159.707, 134.085, 0.138, 0.010, 89.013, 67.612},
	{110.391, 66.017, -158.262, 144.508, 0.129, 0.010, 89.667, 67.700},
	{111.035, 64.449, -156.734, 152.814, 0.120, 0.010, 90.307, 67.780},
	{111.664, 62.898, -155.141, 159.255, 0.111, 0.010, 90.932, 67.852},
	{112.278, 61.363, -153.500, 164.052, 0.104, 0.010, 91.542, 67.918},
	{112.876, 59.845, -151.826, 167.433, 0.096, 0.010, 92.137, 67.978},
	{113.460, 58.343, -150.130, 169.584, 0.089, 0.010, 92.718, 68.031},
	{114.028, 56.859, -148.423, 170.681, 0.082, 0.010, 93.285, 68.080},
	{114.582, 55.392, -146.714, 170.907, 0.076, 0.010, 93.837, 68.124},
	{115.121, 53.942, -145.011, 170.380, 0.070, 0.010, 94.375, 68.163},
	{115.647, 52.509, -143.318, 169.245, 0.064, 0.010, 94.899, 68.198},
	{116.157, 51.092, -141.642, 167.608, 0.059, 0.010, 95.409, 68.230},
	{116.654, 49.692, -139.986, 165.567, 0.054, 0.010, 95.905, 68.258},
	{117.137, 48.309, -138.354, 163.201, 0.050, 0.010, 96.387, 68.283},
	{117.607, 46.941, -136.749, 160.588, 0.045, 0.010, 96.856, 68.305},
	{118.063, 45.590, -135.171, 157.784, 0.041, 0.010, 97.312, 68.325},
	{118.505, 44.253, -133.622, 154.836, 0.037, 0.010, 97.754, 68.342},
	{118.935, 42.932, -132.104, 151.783, 0.034, 0.010, 98.183, 68.358},
	{119.351, 41.626, -130.618, 148.671, 0.031, 0.010, 98.599, 68.371},
	{119.754, 40.335, -129.163, 145.509, 0.028, 0.010, 99.002, 68.383},
	{120.145, 39.057, -127.739, 142.325, 0.025, 0.010, 99.392, 68.393},
	{120.523, 37.794, -126.348, 139.134, 0.022, 0.010, 99.770, 68.402},
	{120.888, 36.544, -124.989, 135.945, 0.020, 0.010, 100.136, 68.410},
	{121.241, 35.307, -123.661, 132.761, 0.018, 0.010, 100.489, 68.416},
	{121.582, 34.084, -122.365, 129.586, 0.016, 0.010, 100.829, 68.422},
	{121.911, 32.873, -121.101, 126.423, 0.014, 0.010, 101.158, 68.427},
	{122.228, 31.674, -119.868, 123.265, 0.012, 0.010, 101.475, 68.431},
	{122.532, 30.487, -118.667, 120.112, 0.011, 0.010, 101.780, 68.435},
	{122.826, 29.312, -117.498, 116.953, 0.009, 0.010, 102.073, 68.437},
	{123.107, 28.149, -116.360, 113.788, 0.008, 0.010, 102.354, 68.440},
	{123.377, 26.996, -115.254, 110.602, 0.007, 0.010, 102.624, 68.442},
	{123.636, 25.854, -114.180, 107.392, 0.006, 0.010, 102.883, 68.444},
	{123.883, 24.723, -113.138, 104.147, 0.005, 0.010, 103.130, 68.445},
	{124.119, 23.602, -112.130, 100.859, 0.004, 0.010, 103.366, 68.446},
	{124.344, 22.490, -111.155, 97.519, 0.004, 0.010, 103.591, 68.447},
	{124.558, 21.388, -110.213, 94.120, 0.003, 0.010, 103.805, 68.448},
	{124.761, 20.295, -109.307, 90.653, 0.003, 0.010, 104.008, 68.448},
	{124.953, 19.210, -108.436, 87.113, 0.002, 0.010, 104.200, 68.449},
	{125.134, 18.134, -107.601, 83.491, 0.002, 0.010, 104.381, 68.449},
	{125.305, 17.066, -106.803, 79.784, 0.001, 0.010, 104.552, 68.449},
	{125.465, 16.006, -106.043, 75.987, 0.001, 0.010, 104.712, 68.450},
	{125.614, 14.953, -105.322, 72.096, 0.001, 0.010, 104.861, 68.450},
	{125.753, 13.906, -104.641, 68.108, 0.001, 0.010, 105.001, 68.450},
	{125.882, 12.866, -104.001, 64.025, 0.000, 0.010, 105.129, 68.450},
	{126.000, 11.832, -103.402, 59.844, 0.000, 0.010, 105.247, 68.450},
	{126.108, 10.804, -102.847, 55.567, 0.000, 0.010, 105.356, 68.450},
	{126.206, 9.781, -102.335, 51.196, 0.000, 0.010, 105.453, 68.450},
	{126.294, 8.762, -101.867, 46.736, 0.000, 0.010, 105.541, 68.450},
	{126.371, 7.770, -99.165, 270.252, 0.000, 0.010, 105.619, 68.450},
	{126.440, 6.834, -93.575, 559.026, 0.000, 0.010, 105.687, 68.450},
	{126.499, 5.961, -87.384, 619.067, 0.000, 0.010, 105.747, 68.450},
	{126.551, 5.148, -81.253, 613.044, 0.000, 0.010, 105.798, 68.450},
	{126.595, 4.396, -75.176, 607.774, 0.000, 0.010, 105.842, 68.450},
	{126.632, 3.705, -69.144, 603.215, 0.000, 0.010, 105.879, 68.450},
	{126.663, 3.073, -63.150, 599.322, 0.000, 0.010, 105.910, 68.450},
	{126.688, 2.501, -57.190, 596.048, 0.000, 0.010, 105.935, 68.450},
	{126.708, 1.989, -51.256, 593.345, 0.000, 0.010, 105.955, 68.450},
	{126.723, 1.535, -45.345, 591.160, 0.000, 0.010, 105.970, 68.450},
	{126.734, 1.141, -39.450, 589.440, 0.000, 0.010, 105.982, 68.450},
	{126.742, 0.805, -33.569, 588.132, 0.000, 0.010, 105.990, 68.450},
	{126.748, 0.528, -27.697, 587.180, 0.000, 0.010, 105.995, 68.450},
	{126.751, 0.310, -21.832, 586.527, 0.000, 0.010, 105.998, 68.450},
	{126.752, 0.150, -15.971, 586.117, 0.000, 0.010, 105.999, 68.450},
	{126.753, 0.049, -10.112, 585.892, 0.000, 0.010, 106.000, 68.450},
	{126.753, 0.007, -4.254, 585.796, 0.000, 0.010, 106.000, 68.450},
	{126.753, 0.000, -0.663, 359.144, 0.000, 0.010, 106.000, 68.450}};
	double right_wheel[244][8] ={
	{0.000, 0.059, 5.858, 585.768, 0.000, 0.010, 0.000, -12.450},
	{0.001, 0.117, 5.858, 0.017, 0.000, 0.010, 0.001, -12.450},
	{0.004, 0.264, 14.645, 878.740, 0.000, 0.010, 0.004, -12.450},
	{0.009, 0.469, 20.506, 586.046, 0.000, 0.010, 0.009, -12.450},
	{0.016, 0.732, 26.370, 586.407, 0.000, 0.010, 0.016, -12.450},
	{0.027, 1.055, 32.240, 586.998, 0.000, 0.010, 0.027, -12.450},
	{0.041, 1.436, 38.119, 587.875, 0.000, 0.010, 0.041, -12.450},
	{0.060, 1.876, 44.009, 589.096, 0.000, 0.010, 0.060, -12.450},
	{0.084, 2.375, 49.917, 590.716, 0.000, 0.010, 0.084, -12.450},
	{0.113, 2.934, 55.845, 592.789, 0.000, 0.010, 0.113, -12.450},
	{0.148, 3.552, 61.798, 595.369, 0.000, 0.010, 0.148, -12.450},
	{0.191, 4.229, 67.783, 598.507, 0.000, 0.010, 0.191, -12.450},
	{0.240, 4.968, 73.806, 602.254, 0.000, 0.010, 0.240, -12.450},
	{0.298, 5.766, 79.872, 606.657, 0.000, 0.010, 0.298, -12.450},
	{0.364, 6.626, 85.990, 611.761, 0.000, 0.010, 0.364, -12.450},
	{0.440, 7.548, 92.166, 617.608, 0.000, 0.010, 0.440, -12.450},
	{0.525, 8.532, 98.408, 624.239, 0.000, 0.010, 0.525, -12.450},
	{0.621, 9.550, 101.767, 335.808, 0.000, 0.010, 0.621, -12.450},
	{0.726, 10.572, 102.224, 45.717, 0.000, 0.010, 0.726, -12.450},
	{0.842, 11.599, 102.726, 50.197, 0.000, 0.010, 0.842, -12.450},
	{0.969, 12.632, 103.272, 54.588, 0.001, 0.010, 0.969, -12.450},
	{1.105, 13.670, 103.860, 58.886, 0.001, 0.010, 1.105, -12.450},
	{1.252, 14.715, 104.491, 63.090, 0.001, 0.010, 1.252, -12.450},
	{1.410, 15.767, 105.163, 67.195, 0.001, 0.010, 1.410, -12.449},
	{1.578, 16.826, 105.875, 71.204, 0.002, 0.010, 1.578, -12.449},
	{1.757, 17.892, 106.626, 75.117, 0.002, 0.010, 1.757, -12.449},
	{1.947, 18.966, 107.416, 78.935, 0.002, 0.010, 1.947, -12.448},
	{2.147, 20.049, 108.242, 82.662, 0.003, 0.010, 2.147, -12.448},
	{2.359, 21.140, 109.105, 86.303, 0.004, 0.010, 2.359, -12.447},
	{2.581, 22.240, 110.004, 89.861, 0.004, 0.010, 2.581, -12.446},
	{2.815, 23.349, 110.938, 93.345, 0.005, 0.010, 2.815, -12.445},
	{3.059, 24.468, 111.905, 96.757, 0.006, 0.010, 3.059, -12.444},
	{3.315, 25.597, 112.906, 100.110, 0.007, 0.010, 3.315, -12.442},
	{3.583, 26.737, 113.940, 103.409, 0.008, 0.010, 3.583, -12.440},
	{3.862, 27.887, 115.007, 106.663, 0.009, 0.010, 3.862, -12.438},
	{4.152, 29.048, 116.106, 109.880, 0.010, 0.010, 4.152, -12.435},
	{4.454, 30.220, 117.236, 113.070, 0.012, 0.010, 4.454, -12.432},
	{4.768, 31.404, 118.399, 116.241, 0.013, 0.010, 4.768, -12.428},
	{5.094, 32.600, 119.593, 119.398, 0.015, 0.010, 5.094, -12.423},
	{5.432, 33.808, 120.818, 122.554, 0.017, 0.010, 5.432, -12.418},
	{5.783, 35.029, 122.075, 125.707, 0.019, 0.010, 5.782, -12.411},
	{6.145, 36.262, 123.364, 128.871, 0.022, 0.010, 6.145, -12.404},
	{6.520, 37.509, 124.685, 132.043, 0.024, 0.010, 6.520, -12.395},
	{6.908, 38.770, 126.037, 135.223, 0.027, 0.010, 6.908, -12.385},
	{7.309, 40.044, 127.421, 138.412, 0.030, 0.010, 7.308, -12.374},
	{7.722, 41.332, 128.837, 141.605, 0.033, 0.010, 7.721, -12.361},
	{8.148, 42.635, 130.285, 144.790, 0.037, 0.010, 8.147, -12.346},
	{8.588, 43.953, 131.764, 147.958, 0.040, 0.010, 8.586, -12.329},
	{9.041, 45.286, 133.275, 151.086, 0.044, 0.010, 9.039, -12.310},
	{9.507, 46.634, 134.817, 154.153, 0.049, 0.010, 9.505, -12.288},
	{9.987, 47.998, 136.388, 157.127, 0.053, 0.010, 9.984, -12.264},
	{10.481, 49.377, 137.988, 159.969, 0.058, 0.010, 10.477, -12.237},
	{10.988, 50.774, 139.614, 162.633, 0.063, 0.010, 10.984, -12.206},
	{11.510, 52.186, 141.265, 165.057, 0.069, 0.010, 11.504, -12.172},
	{12.046, 53.616, 142.937, 167.182, 0.075, 0.010, 12.039, -12.133},
	{12.597, 55.062, 144.626, 168.916, 0.081, 0.010, 12.588, -12.091},
	{13.162, 56.525, 146.327, 170.177, 0.087, 0.010, 13.151, -12.043},
	{13.742, 58.006, 148.036, 170.850, 0.094, 0.010, 13.729, -11.990},
	{14.337, 59.503, 149.744, 170.811, 0.102, 0.010, 14.321, -11.932},
	{14.948, 61.017, 151.443, 169.925, 0.110, 0.010, 14.928, -11.868},
	{15.573, 62.549, 153.124, 168.024, 0.118, 0.010, 15.549, -11.797},
	{16.214, 64.096, 154.773, 164.945, 0.127, 0.010, 16.186, -11.719},
	{16.871, 65.660, 156.378, 160.488, 0.136, 0.010, 16.837, -11.633},
	{17.543, 67.239, 157.922, 154.437, 0.145, 0.010, 17.502, -11.539},
	{18.231, 68.833, 159.388, 146.579, 0.155, 0.010, 18.183, -11.436},
	{18.936, 70.441, 160.755, 136.657, 0.166, 0.010, 18.878, -11.323},
	{19.656, 72.061, 161.999, 124.437, 0.177, 0.010, 19.588, -11.200},
	{20.393, 73.692, 163.096, 109.661, 0.189, 0.010, 20.313, -11.066},
	{21.147, 75.332, 164.016, 92.069, 0.201, 0.010, 21.052, -10.920},
	{21.916, 76.979, 164.731, 71.437, 0.213, 0.010, 21.805, -10.762},
	{22.703, 78.631, 165.206, 47.533, 0.227, 0.010, 22.573, -10.590},
	{23.506, 80.285, 165.408, 20.180, 0.240, 0.010, 23.354, -10.404},
	{24.325, 81.938, 165.300, -10.755, 0.255, 0.010, 24.148, -10.204},
	{25.161, 83.587, 164.847, -45.335, 0.269, 0.010, 24.956, -9.987},
	{26.013, 85.227, 164.011, -83.557, 0.285, 0.010, 25.775, -9.754},
	{26.882, 86.854, 162.758, -125.284, 0.300, 0.010, 26.607, -9.504},
	{27.766, 88.465, 161.055, -170.302, 0.317, 0.010, 27.450, -9.235},
	{28.667, 90.054, 158.873, -218.227, 0.333, 0.010, 28.303, -8.948},
	{29.583, 91.616, 156.188, -268.555, 0.351, 0.010, 29.167, -8.641},
	{30.514, 93.145, 152.981, -320.632, 0.368, 0.010, 30.038, -8.313},
	{31.461, 94.638, 149.245, -373.643, 0.386, 0.010, 30.918, -7.965},
	{32.422, 96.088, 144.978, -426.662, 0.405, 0.010, 31.805, -7.594},
	{33.397, 97.490, 140.192, -478.632, 0.423, 0.010, 32.698, -7.202},
	{34.385, 98.839, 134.908, -528.424, 0.442, 0.010, 33.595, -6.788},
	{35.386, 100.130, 129.159, -574.867, 0.462, 0.010, 34.496, -6.350},
	{36.400, 101.360, 122.991, -616.800, 0.481, 0.010, 35.399, -5.890},
	{37.425, 102.525, 116.460, -653.125, 0.501, 0.010, 36.303, -5.407},
	{38.461, 103.621, 109.631, -682.865, 0.520, 0.010, 37.207, -4.901},
	{39.508, 104.647, 102.579, -705.217, 0.540, 0.010, 38.110, -4.372},
	{40.564, 105.601, 95.383, -719.596, 0.559, 0.010, 39.010, -3.820},
	{41.629, 106.482, 88.126, -725.672, 0.579, 0.010, 39.907, -3.246},
	{42.702, 107.291, 80.892, -723.392, 0.598, 0.010, 40.800, -2.650},
	{43.782, 108.029, 73.763, -712.979, 0.618, 0.010, 41.686, -2.033},
	{44.869, 108.697, 66.813, -694.926, 0.637, 0.010, 42.566, -1.395},
	{45.962, 109.298, 60.114, -669.965, 0.655, 0.010, 43.439, -0.738},
	{47.060, 109.835, 53.723, -639.017, 0.673, 0.010, 44.304, -0.060},
	{48.163, 110.312, 47.692, -603.167, 0.691, 0.010, 45.160, 0.635},
	{49.271, 110.733, 42.056, -563.575, 0.709, 0.010, 46.007, 1.349},
	{50.382, 111.101, 36.842, -521.454, 0.725, 0.010, 46.845, 2.079},
	{51.496, 111.422, 32.062, -477.986, 0.742, 0.010, 47.672, 2.825},
	{52.613, 111.699, 27.719, -434.314, 0.757, 0.010, 48.490, 3.586},
	{53.732, 111.937, 23.804, -391.472, 0.773, 0.010, 49.297, 4.361},
	{54.854, 112.140, 20.300, -350.383, 0.787, 0.010, 50.095, 5.149},
	{55.977, 112.312, 17.182, -311.820, 0.801, 0.010, 50.882, 5.950},
	{57.101, 112.456, 14.417, -276.438, 0.814, 0.010, 51.659, 6.763},
	{58.227, 112.542, 8.590, -582.743, 0.826, 0.010, 52.427, 7.586},
	{59.352, 112.540, -0.183, -877.337, 0.838, 0.010, 53.184, 8.418},
	{60.477, 112.455, -8.473, -828.920, 0.849, 0.010, 53.932, 9.259},
	{61.599, 112.292, -16.326, -785.329, 0.859, 0.010, 54.669, 10.105},
	{62.720, 112.054, -23.793, -746.760, 0.869, 0.010, 55.397, 10.957},
	{63.837, 111.745, -30.926, -713.234, 0.877, 0.010, 56.115, 11.814},
	{64.951, 111.367, -37.772, -684.638, 0.885, 0.010, 56.823, 12.673},
	{66.060, 110.923, -44.380, -660.743, 0.892, 0.010, 57.523, 13.534},
	{67.165, 110.415, -50.792, -641.237, 0.898, 0.010, 58.213, 14.396},
	{68.263, 109.845, -57.049, -625.748, 0.904, 0.010, 58.895, 15.257},
	{69.355, 109.213, -63.188, -613.852, 0.908, 0.010, 59.568, 16.117},
	{70.440, 108.520, -69.239, -605.110, 0.912, 0.010, 60.234, 16.974},
	{71.518, 107.768, -75.230, -599.056, 0.915, 0.010, 60.893, 17.827},
	{72.588, 106.956, -81.182, -595.218, 0.917, 0.010, 61.544, 18.675},
	{73.648, 106.085, -87.113, -593.125, 0.919, 0.010, 62.188, 19.518},
	{74.700, 105.155, -93.036, -592.303, 0.919, 0.010, 62.826, 20.354},
	{75.741, 104.143, -101.206, -816.947, 0.919, 0.010, 63.458, 21.182},
	{76.772, 103.050, -109.290, -808.401, 0.918, 0.010, 64.084, 22.001},
	{77.791, 101.899, -115.084, -579.403, 0.916, 0.010, 64.704, 22.809},
	{78.798, 100.690, -120.872, -578.798, 0.913, 0.010, 65.318, 23.607},
	{79.792, 99.424, -126.642, -577.030, 0.909, 0.010, 65.928, 24.393},
	{80.773, 98.100, -132.378, -573.624, 0.905, 0.010, 66.532, 25.165},
	{81.740, 96.720, -138.059, -568.107, 0.900, 0.010, 67.131, 25.924},
	{82.693, 95.283, -143.659, -560.009, 0.894, 0.010, 67.726, 26.669},
	{83.631, 93.791, -149.148, -548.862, 0.887, 0.010, 68.316, 27.398},
	{84.553, 92.247, -154.490, -534.217, 0.879, 0.010, 68.902, 28.111},
	{85.460, 90.650, -159.647, -515.648, 0.871, 0.010, 69.483, 28.806},
	{86.350, 89.004, -164.574, -492.773, 0.861, 0.010, 70.059, 29.484},
	{87.223, 87.312, -169.227, -465.254, 0.851, 0.010, 70.631, 30.144},
	{88.079, 85.577, -173.555, -432.852, 0.841, 0.010, 71.198, 30.785},
	{88.917, 83.801, -177.510, -395.421, 0.829, 0.010, 71.761, 31.406},
	{89.737, 81.991, -181.039, -352.947, 0.817, 0.010, 72.318, 32.007},
	{90.538, 80.150, -184.095, -305.586, 0.804, 0.010, 72.871, 32.588},
	{91.321, 78.302, -184.782, -68.739, 0.790, 0.010, 73.418, 33.148},
	{92.086, 76.476, -182.648, 213.407, 0.776, 0.010, 73.960, 33.688},
	{92.833, 74.680, -179.613, 303.501, 0.761, 0.010, 74.497, 34.207},
	{93.562, 72.918, -176.199, 341.404, 0.745, 0.010, 75.029, 34.706},
	{94.274, 71.194, -172.379, 381.998, 0.729, 0.010, 75.556, 35.184},
	{94.969, 69.513, -168.134, 424.532, 0.712, 0.010, 76.078, 35.643},
	{95.648, 67.878, -163.453, 468.117, 0.695, 0.010, 76.595, 36.082},
	{96.311, 66.295, -158.335, 511.739, 0.677, 0.010, 77.108, 36.503},
	{96.959, 64.767, -152.792, 554.285, 0.659, 0.010, 77.616, 36.904},
	{97.591, 63.298, -146.847, 594.567, 0.641, 0.010, 78.120, 37.287},
	{98.210, 61.893, -140.533, 631.384, 0.622, 0.010, 78.620, 37.652},
	{98.816, 60.554, -133.897, 663.551, 0.603, 0.010, 79.115, 38.001},
	{99.409, 59.284, -126.998, 689.966, 0.583, 0.010, 79.607, 38.332},
	{99.990, 58.085, -119.901, 709.663, 0.564, 0.010, 80.095, 38.647},
	{100.559, 56.958, -112.682, 721.865, 0.544, 0.010, 80.579, 38.947},
	{101.118, 55.904, -105.422, 726.018, 0.525, 0.010, 81.060, 39.232},
	{101.667, 54.922, -98.204, 721.841, 0.505, 0.010, 81.538, 39.502},
	{102.208, 54.011, -91.111, 709.321, 0.485, 0.010, 82.013, 39.759},
	{102.739, 53.169, -84.223, 688.727, 0.466, 0.010, 82.486, 40.002},
	{103.263, 52.392, -77.617, 660.590, 0.447, 0.010, 82.956, 40.233},
	{103.780, 51.679, -71.361, 625.667, 0.428, 0.010, 83.425, 40.452},
	{104.290, 51.024, -65.512, 584.901, 0.409, 0.010, 83.891, 40.659},
	{104.794, 50.422, -60.118, 539.367, 0.390, 0.010, 84.355, 40.855},
	{105.293, 49.870, -55.216, 490.218, 0.372, 0.010, 84.818, 41.041},
	{105.787, 49.362, -50.830, 438.626, 0.355, 0.010, 85.280, 41.216},
	{106.276, 48.892, -46.972, 385.739, 0.337, 0.010, 85.740, 41.382},
	{106.760, 48.456, -43.646, 332.623, 0.320, 0.010, 86.198, 41.539},
	{107.241, 48.047, -40.844, 280.250, 0.304, 0.010, 86.656, 41.686},
	{107.717, 47.662, -38.549, 229.452, 0.288, 0.010, 87.111, 41.825},
	{108.190, 47.295, -36.740, 180.920, 0.273, 0.010, 87.566, 41.956},
	{108.660, 46.941, -35.388, 135.202, 0.258, 0.010, 88.019, 42.079},
	{109.126, 46.596, -34.461, 92.691, 0.244, 0.010, 88.470, 42.195},
	{109.588, 46.257, -33.924, 53.660, 0.230, 0.010, 88.920, 42.303},
	{110.047, 45.919, -33.742, 18.242, 0.216, 0.010, 89.368, 42.405},
	{110.503, 45.581, -33.877, -13.520, 0.204, 0.010, 89.814, 42.500},
	{110.956, 45.238, -34.294, -41.676, 0.191, 0.010, 90.257, 42.588},
	{111.404, 44.888, -34.957, -66.348, 0.180, 0.010, 90.698, 42.671},
	{111.850, 44.530, -35.834, -87.706, 0.168, 0.010, 91.137, 42.748},
	{112.291, 44.161, -36.894, -105.967, 0.158, 0.010, 91.573, 42.820},
	{112.729, 43.780, -38.108, -121.357, 0.148, 0.010, 92.005, 42.887},
	{113.163, 43.385, -39.449, -134.138, 0.138, 0.010, 92.435, 42.948},
	{113.593, 42.976, -40.895, -144.552, 0.129, 0.010, 92.861, 43.005},
	{114.018, 42.552, -42.423, -152.859, 0.120, 0.010, 93.283, 43.058},
	{114.439, 42.112, -44.016, -159.294, 0.111, 0.010, 93.701, 43.107},
	{114.856, 41.655, -45.657, -164.095, 0.104, 0.010, 94.115, 43.151},
	{115.268, 41.182, -47.332, -167.466, 0.096, 0.010, 94.525, 43.192},
	{115.675, 40.692, -49.028, -169.614, 0.089, 0.010, 94.930, 43.230},
	{116.077, 40.184, -50.735, -170.718, 0.082, 0.010, 95.331, 43.264},
	{116.473, 39.660, -52.444, -170.929, 0.076, 0.010, 95.726, 43.296},
	{116.864, 39.118, -54.148, -170.407, 0.070, 0.010, 96.116, 43.324},
	{117.250, 38.560, -55.841, -169.269, 0.064, 0.010, 96.501, 43.350},
	{117.630, 37.985, -57.517, -167.629, 0.059, 0.010, 96.880, 43.373},
	{118.004, 37.393, -59.173, -165.585, 0.054, 0.010, 97.253, 43.395},
	{118.372, 36.785, -60.805, -163.221, 0.050, 0.010, 97.621, 43.414},
	{118.733, 36.161, -62.411, -160.604, 0.045, 0.010, 97.982, 43.431},
	{119.088, 35.521, -63.989, -157.795, 0.041, 0.010, 98.337, 43.446},
	{119.437, 34.866, -65.538, -154.847, 0.037, 0.010, 98.685, 43.460},
	{119.779, 34.195, -67.056, -151.800, 0.034, 0.010, 99.027, 43.472},
	{120.114, 33.510, -68.543, -148.677, 0.031, 0.010, 99.362, 43.483},
	{120.442, 32.810, -69.998, -145.518, 0.028, 0.010, 99.690, 43.492},
	{120.763, 32.096, -71.421, -142.334, 0.025, 0.010, 100.011, 43.501},
	{121.077, 31.367, -72.813, -139.141, 0.022, 0.010, 100.324, 43.508},
	{121.383, 30.626, -74.172, -135.949, 0.020, 0.010, 100.631, 43.515},
	{121.682, 29.871, -75.500, -132.765, 0.018, 0.010, 100.929, 43.520},
	{121.973, 29.103, -76.796, -129.592, 0.016, 0.010, 101.220, 43.525},
	{122.256, 28.322, -78.060, -126.426, 0.014, 0.010, 101.503, 43.529},
	{122.531, 27.529, -79.293, -123.269, 0.012, 0.010, 101.779, 43.533},
	{122.799, 26.724, -80.494, -120.114, 0.011, 0.010, 102.046, 43.536},
	{123.058, 25.908, -81.663, -116.957, 0.009, 0.010, 102.305, 43.539},
	{123.308, 25.080, -82.801, -113.789, 0.008, 0.010, 102.556, 43.541},
	{123.551, 24.241, -83.907, -110.604, 0.007, 0.010, 102.798, 43.543},
	{123.785, 23.391, -84.981, -107.393, 0.006, 0.010, 103.032, 43.544},
	{124.010, 22.531, -86.023, -104.148, 0.005, 0.010, 103.257, 43.545},
	{124.227, 21.660, -87.031, -100.860, 0.004, 0.010, 103.474, 43.546},
	{124.434, 20.780, -88.006, -97.520, 0.004, 0.010, 103.682, 43.547},
	{124.633, 19.891, -88.948, -94.121, 0.003, 0.010, 103.881, 43.548},
	{124.823, 18.992, -89.854, -90.655, 0.003, 0.010, 104.071, 43.548},
	{125.004, 18.085, -90.725, -87.113, 0.002, 0.010, 104.251, 43.549},
	{125.176, 17.169, -91.560, -83.492, 0.002, 0.010, 104.423, 43.549},
	{125.338, 16.246, -92.358, -79.785, 0.001, 0.010, 104.586, 43.549},
	{125.491, 15.315, -93.118, -75.987, 0.001, 0.010, 104.739, 43.550},
	{125.635, 14.376, -93.839, -72.096, 0.001, 0.010, 104.882, 43.550},
	{125.770, 13.431, -94.520, -68.109, 0.001, 0.010, 105.017, 43.550},
	{125.894, 12.479, -95.160, -64.025, 0.000, 0.010, 105.142, 43.550},
	{126.010, 11.522, -95.759, -59.844, 0.000, 0.010, 105.257, 43.550},
	{126.115, 10.559, -96.314, -55.567, 0.000, 0.010, 105.362, 43.550},
	{126.211, 9.590, -96.826, -51.197, 0.000, 0.010, 105.458, 43.550},
	{126.297, 8.617, -97.294, -46.736, 0.000, 0.010, 105.544, 43.550},
	{126.374, 7.663, -95.464, 183.002, 0.000, 0.010, 105.621, 43.550},
	{126.441, 6.756, -90.664, 479.995, 0.000, 0.010, 105.689, 43.550},
	{126.500, 5.905, -85.139, 552.468, 0.000, 0.010, 105.748, 43.550},
	{126.552, 5.109, -79.554, 558.491, 0.000, 0.010, 105.799, 43.550},
	{126.595, 4.370, -73.917, 563.762, 0.000, 0.010, 105.842, 43.550},
	{126.632, 3.688, -68.233, 568.321, 0.000, 0.010, 105.879, 43.550},
	{126.663, 3.063, -62.511, 572.214, 0.000, 0.010, 105.910, 43.550},
	{126.688, 2.495, -56.756, 575.487, 0.000, 0.010, 105.935, 43.550},
	{126.708, 1.985, -50.974, 578.191, 0.000, 0.010, 105.955, 43.550},
	{126.723, 1.534, -45.171, 580.376, 0.000, 0.010, 105.970, 43.550},
	{126.734, 1.140, -39.350, 582.095, 0.000, 0.010, 105.982, 43.550},
	{126.742, 0.805, -33.516, 583.403, 0.000, 0.010, 105.990, 43.550},
	{126.748, 0.528, -27.672, 584.356, 0.000, 0.010, 105.995, 43.550},
	{126.751, 0.310, -21.822, 585.009, 0.000, 0.010, 105.998, 43.550},
	{126.752, 0.150, -15.968, 585.419, 0.000, 0.010, 105.999, 43.550},
	{126.753, 0.049, -10.111, 585.643, 0.000, 0.010, 106.000, 43.550},
	{126.753, 0.007, -4.254, 585.740, 0.000, 0.010, 106.000, 43.550},
	{126.753, 0.000, -0.663, 359.139, 0.000, 0.010, 106.000, 43.550}};

};
#endif
