#ifndef FromRightFirstCube_ToLeftScalePath_H
#define FromRightFirstCube_ToLeftScalePath_H
int num_index = 290;
double left_wheel[290][8] ={ 
{0.000, 0.060, 6.000, 600.000, 1.571, 0.010, 202.550, 25.001},
{0.002, 0.120, 6.000, 0.002, 1.571, 0.010, 202.550, 25.003},
{0.004, 0.270, 15.000, 900.012, 1.571, 0.010, 202.550, 25.005},
{0.009, 0.480, 21.001, 600.037, 1.571, 0.010, 202.550, 25.010},
{0.017, 0.750, 27.001, 600.086, 1.571, 0.010, 202.550, 25.018},
{0.027, 1.080, 33.003, 600.165, 1.571, 0.010, 202.550, 25.029},
{0.042, 1.470, 39.006, 600.283, 1.571, 0.010, 202.550, 25.043},
{0.061, 1.920, 45.010, 600.446, 1.571, 0.010, 202.550, 25.062},
{0.086, 2.430, 51.017, 600.663, 1.571, 0.010, 202.550, 25.087},
{0.116, 3.001, 57.026, 600.941, 1.571, 0.010, 202.550, 25.117},
{0.152, 3.631, 63.039, 601.286, 1.571, 0.010, 202.550, 25.153},
{0.195, 4.322, 69.056, 601.706, 1.571, 0.010, 202.550, 25.196},
{0.246, 5.072, 75.078, 602.207, 1.571, 0.010, 202.550, 25.247},
{0.305, 5.883, 81.106, 602.795, 1.571, 0.010, 202.550, 25.306},
{0.372, 6.755, 87.141, 603.475, 1.571, 0.010, 202.550, 25.373},
{0.449, 7.687, 93.184, 604.253, 1.571, 0.010, 202.550, 25.450},
{0.536, 8.679, 99.235, 605.133, 1.571, 0.010, 202.550, 25.537},
{0.633, 9.732, 105.296, 606.120, 1.571, 0.010, 202.550, 25.634},
{0.742, 10.846, 111.368, 607.215, 1.571, 0.010, 202.550, 25.743},
{0.862, 12.020, 117.452, 608.421, 1.571, 0.010, 202.550, 25.863},
{0.994, 13.226, 120.544, 309.116, 1.571, 0.010, 202.550, 25.995},
{1.138, 14.432, 120.638, 9.482, 1.571, 0.010, 202.550, 26.140},
{1.295, 15.639, 120.741, 10.219, 1.571, 0.010, 202.550, 26.296},
{1.463, 16.848, 120.850, 10.924, 1.571, 0.010, 202.550, 26.464},
{1.644, 18.058, 120.966, 11.595, 1.570, 0.010, 202.550, 26.645},
{1.836, 19.268, 121.088, 12.229, 1.570, 0.010, 202.550, 26.838},
{2.041, 20.481, 121.216, 12.824, 1.570, 0.010, 202.550, 27.043},
{2.258, 21.694, 121.350, 13.378, 1.570, 0.010, 202.551, 27.259},
{2.487, 22.909, 121.489, 13.888, 1.570, 0.010, 202.551, 27.489},
{2.729, 24.125, 121.633, 14.352, 1.570, 0.010, 202.551, 27.730},
{2.982, 25.343, 121.780, 14.768, 1.570, 0.010, 202.551, 27.983},
{3.248, 26.562, 121.932, 15.134, 1.570, 0.010, 202.551, 28.249},
{3.525, 27.783, 122.086, 15.449, 1.570, 0.010, 202.552, 28.527},
{3.816, 29.006, 122.243, 15.710, 1.570, 0.010, 202.552, 28.817},
{4.118, 30.230, 122.402, 15.915, 1.569, 0.010, 202.552, 29.119},
{4.432, 31.455, 122.563, 16.064, 1.569, 0.010, 202.553, 29.434},
{4.759, 32.683, 122.724, 16.154, 1.569, 0.010, 202.553, 29.760},
{5.098, 33.912, 122.886, 16.183, 1.569, 0.010, 202.554, 30.100},
{5.450, 35.142, 123.048, 16.151, 1.568, 0.010, 202.555, 30.451},
{5.813, 36.374, 123.208, 16.056, 1.568, 0.010, 202.556, 30.815},
{6.190, 37.608, 123.367, 15.897, 1.568, 0.010, 202.557, 31.191},
{6.578, 38.843, 123.524, 15.673, 1.567, 0.010, 202.558, 31.579},
{6.979, 40.080, 123.678, 15.383, 1.567, 0.010, 202.560, 31.980},
{7.392, 41.318, 123.828, 15.025, 1.567, 0.010, 202.561, 32.393},
{7.818, 42.558, 123.974, 14.599, 1.566, 0.010, 202.563, 32.819},
{8.256, 43.799, 124.115, 14.105, 1.566, 0.010, 202.565, 33.257},
{8.706, 45.041, 124.251, 13.542, 1.565, 0.010, 202.568, 33.707},
{9.169, 46.285, 124.380, 12.909, 1.565, 0.010, 202.570, 34.170},
{9.644, 47.530, 124.502, 12.207, 1.564, 0.010, 202.573, 34.645},
{10.132, 48.776, 124.616, 11.434, 1.563, 0.010, 202.577, 35.133},
{10.632, 50.024, 124.722, 10.591, 1.563, 0.010, 202.581, 35.633},
{11.145, 51.272, 124.819, 9.678, 1.562, 0.010, 202.585, 36.146},
{11.670, 52.521, 124.906, 8.696, 1.561, 0.010, 202.590, 36.671},
{12.208, 53.771, 124.982, 7.645, 1.561, 0.010, 202.595, 37.209},
{12.758, 55.021, 125.047, 6.524, 1.560, 0.010, 202.601, 37.759},
{13.321, 56.272, 125.101, 5.336, 1.559, 0.010, 202.608, 38.322},
{13.896, 57.524, 125.142, 4.081, 1.558, 0.010, 202.615, 38.897},
{14.484, 58.775, 125.169, 2.760, 1.557, 0.010, 202.622, 39.485},
{15.084, 60.027, 125.183, 1.375, 1.556, 0.010, 202.631, 40.085},
{15.697, 61.279, 125.182, -0.073, 1.555, 0.010, 202.640, 40.697},
{16.322, 62.531, 125.166, -1.583, 1.554, 0.010, 202.651, 41.323},
{16.960, 63.782, 125.135, -3.152, 1.553, 0.010, 202.662, 41.960},
{17.610, 65.033, 125.087, -4.779, 1.552, 0.010, 202.674, 42.611},
{18.273, 66.283, 125.023, -6.460, 1.550, 0.010, 202.687, 43.273},
{18.948, 67.532, 124.941, -8.194, 1.549, 0.010, 202.701, 43.949},
{19.636, 68.781, 124.841, -9.977, 1.548, 0.010, 202.716, 44.636},
{20.336, 70.028, 124.723, -11.806, 1.547, 0.010, 202.733, 45.336},
{21.049, 71.274, 124.586, -13.679, 1.545, 0.010, 202.751, 46.049},
{21.774, 72.518, 124.430, -15.590, 1.544, 0.010, 202.769, 46.774},
{22.512, 73.761, 124.255, -17.538, 1.543, 0.010, 202.790, 47.511},
{23.262, 75.001, 124.060, -19.516, 1.541, 0.010, 202.812, 48.261},
{24.024, 76.240, 123.844, -21.522, 1.540, 0.010, 202.835, 49.023},
{24.799, 77.476, 123.609, -23.550, 1.538, 0.010, 202.860, 49.797},
{25.586, 78.709, 123.353, -25.595, 1.537, 0.010, 202.886, 50.584},
{26.386, 79.940, 123.076, -27.652, 1.535, 0.010, 202.914, 51.383},
{27.197, 81.168, 122.779, -29.715, 1.533, 0.010, 202.944, 52.194},
{28.021, 82.393, 122.461, -31.779, 1.532, 0.010, 202.975, 53.017},
{28.857, 83.614, 122.123, -33.838, 1.530, 0.010, 203.008, 53.853},
{29.706, 84.832, 121.764, -35.885, 1.529, 0.010, 203.043, 54.700},
{30.566, 86.045, 121.385, -37.914, 1.527, 0.010, 203.081, 55.560},
{31.439, 87.255, 120.986, -39.918, 1.525, 0.010, 203.120, 56.432},
{32.323, 88.461, 120.567, -41.890, 1.524, 0.010, 203.161, 57.315},
{33.220, 89.662, 120.129, -43.822, 1.522, 0.010, 203.204, 58.211},
{34.129, 90.859, 119.672, -45.708, 1.520, 0.010, 203.249, 59.118},
{35.049, 92.051, 119.196, -47.539, 1.519, 0.010, 203.296, 60.038},
{35.981, 93.238, 118.703, -49.308, 1.517, 0.010, 203.345, 60.969},
{36.926, 94.420, 118.193, -51.006, 1.515, 0.010, 203.397, 61.911},
{37.882, 95.596, 117.667, -52.625, 1.514, 0.010, 203.450, 62.866},
{38.849, 96.768, 117.125, -54.157, 1.512, 0.010, 203.506, 63.832},
{39.829, 97.933, 116.569, -55.594, 1.511, 0.010, 203.565, 64.810},
{40.820, 99.093, 116.000, -56.925, 1.509, 0.010, 203.625, 65.799},
{41.822, 100.248, 115.419, -58.144, 1.508, 0.010, 203.687, 66.799},
{42.836, 101.396, 114.826, -59.239, 1.506, 0.010, 203.752, 67.811},
{43.861, 102.538, 114.224, -60.202, 1.505, 0.010, 203.819, 68.834},
{44.898, 103.674, 113.614, -61.024, 1.503, 0.010, 203.888, 69.869},
{45.946, 104.804, 112.997, -61.694, 1.502, 0.010, 203.959, 70.914},
{47.005, 105.928, 112.375, -62.203, 1.501, 0.010, 204.033, 71.971},
{48.076, 107.045, 111.750, -62.540, 1.500, 0.010, 204.108, 73.039},
{49.157, 108.157, 111.123, -62.695, 1.499, 0.010, 204.185, 74.118},
{50.250, 109.262, 110.496, -62.657, 1.498, 0.010, 204.264, 75.207},
{51.353, 110.330, 106.842, -365.442, 1.497, 0.010, 204.346, 76.308},
{52.467, 111.332, 100.178, -666.354, 1.496, 0.010, 204.428, 77.418},
{53.589, 112.267, 93.549, -662.892, 1.495, 0.010, 204.513, 78.537},
{54.721, 113.137, 86.959, -659.031, 1.494, 0.010, 204.599, 79.666},
{55.860, 113.941, 80.411, -654.788, 1.494, 0.010, 204.686, 80.802},
{57.007, 114.680, 73.909, -650.180, 1.493, 0.010, 204.774, 81.945},
{58.160, 115.355, 67.457, -645.230, 1.493, 0.010, 204.863, 83.095},
{59.320, 115.965, 61.057, -639.959, 1.493, 0.010, 204.954, 84.251},
{60.485, 116.512, 54.713, -634.395, 1.493, 0.010, 205.044, 85.413},
{61.655, 116.997, 48.428, -628.564, 1.493, 0.010, 205.135, 86.579},
{62.829, 117.419, 42.203, -622.496, 1.493, 0.010, 205.227, 87.750},
{64.007, 117.779, 36.041, -616.222, 1.493, 0.010, 205.318, 88.924},
{65.188, 118.079, 29.943, -609.774, 1.494, 0.010, 205.410, 90.101},
{66.371, 118.318, 23.911, -603.187, 1.494, 0.010, 205.501, 91.281},
{67.556, 118.497, 17.946, -596.495, 1.495, 0.010, 205.591, 92.463},
{68.742, 118.618, 12.049, -589.736, 1.495, 0.010, 205.681, 93.645},
{69.929, 118.680, 6.219, -582.946, 1.496, 0.010, 205.770, 94.829},
{71.116, 118.684, 0.458, -576.165, 1.497, 0.010, 205.858, 96.012},
{72.302, 118.632, -5.237, -569.432, 1.498, 0.010, 205.945, 97.196},
{73.487, 118.523, -10.865, -562.785, 1.499, 0.010, 206.030, 98.378},
{74.671, 118.389, -13.469, -260.460, 1.501, 0.010, 206.114, 99.559},
{75.854, 118.258, -13.068, 40.091, 1.502, 0.010, 206.196, 100.738},
{77.035, 118.132, -12.630, 43.826, 1.504, 0.010, 206.276, 101.917},
{78.215, 118.010, -12.154, 47.574, 1.505, 0.010, 206.354, 103.094},
{79.394, 117.894, -11.641, 51.335, 1.507, 0.010, 206.430, 104.271},
{80.572, 117.783, -11.090, 55.107, 1.509, 0.010, 206.505, 105.446},
{81.749, 117.678, -10.501, 58.890, 1.511, 0.010, 206.577, 106.621},
{82.925, 117.579, -9.874, 62.680, 1.512, 0.010, 206.646, 107.795},
{84.100, 117.487, -9.209, 66.478, 1.515, 0.010, 206.713, 108.968},
{85.274, 117.402, -8.507, 70.279, 1.517, 0.010, 206.778, 110.140},
{86.447, 117.324, -7.766, 74.082, 1.519, 0.010, 206.841, 111.311},
{87.619, 117.254, -6.987, 77.884, 1.521, 0.010, 206.900, 112.482},
{88.791, 117.193, -6.170, 81.682, 1.523, 0.010, 206.957, 113.653},
{89.963, 117.140, -5.315, 85.473, 1.526, 0.010, 207.012, 114.823},
{91.134, 117.095, -4.423, 89.254, 1.528, 0.010, 207.063, 115.993},
{92.304, 117.060, -3.493, 93.023, 1.530, 0.010, 207.112, 117.163},
{93.475, 117.035, -2.525, 96.777, 1.533, 0.010, 207.158, 118.332},
{94.645, 117.020, -1.520, 100.514, 1.535, 0.010, 207.202, 119.501},
{95.815, 117.015, -0.477, 104.231, 1.537, 0.010, 207.242, 120.671},
{96.985, 117.021, 0.602, 107.927, 1.540, 0.010, 207.280, 121.840},
{98.156, 117.038, 1.718, 111.601, 1.542, 0.010, 207.315, 123.010},
{99.326, 117.067, 2.870, 115.252, 1.544, 0.010, 207.347, 124.181},
{100.497, 117.108, 4.059, 118.880, 1.547, 0.010, 207.377, 125.351},
{101.669, 117.161, 5.284, 122.486, 1.549, 0.010, 207.403, 126.523},
{102.841, 117.226, 6.545, 126.072, 1.551, 0.010, 207.427, 127.695},
{104.014, 117.304, 7.841, 129.639, 1.553, 0.010, 207.449, 128.867},
{105.188, 117.396, 9.173, 133.190, 1.556, 0.010, 207.468, 130.041},
{106.363, 117.501, 10.540, 136.730, 1.558, 0.010, 207.485, 131.216},
{107.539, 117.621, 11.943, 140.263, 1.560, 0.010, 207.499, 132.392},
{108.717, 117.755, 13.381, 143.795, 1.561, 0.010, 207.511, 133.570},
{109.896, 117.903, 14.854, 147.331, 1.563, 0.010, 207.522, 134.749},
{111.077, 118.067, 16.363, 150.879, 1.565, 0.010, 207.530, 135.929},
{112.259, 118.246, 17.907, 154.446, 1.566, 0.010, 207.536, 137.112},
{113.444, 118.441, 19.488, 158.039, 1.567, 0.010, 207.541, 138.296},
{114.630, 118.652, 21.105, 161.666, 1.568, 0.010, 207.545, 139.483},
{115.819, 118.879, 22.758, 165.336, 1.569, 0.010, 207.547, 140.671},
{117.010, 119.124, 24.448, 169.055, 1.570, 0.010, 207.549, 141.863},
{118.204, 119.386, 26.177, 172.830, 1.570, 0.010, 207.550, 143.057},
{119.401, 119.665, 27.943, 176.667, 1.571, 0.010, 207.550, 144.253},
{120.601, 120.043, 37.733, 978.989, 1.571, 0.010, 207.550, 145.454},
{121.813, 121.244, 120.125, 8239.166, 1.570, 0.010, 207.551, 146.666},
{123.040, 122.625, 138.130, 1800.521, 1.568, 0.010, 207.553, 147.892},
{124.280, 123.984, 135.927, -220.301, 1.564, 0.010, 207.559, 149.132},
{125.533, 125.343, 135.838, -8.874, 1.560, 0.010, 207.570, 150.386},
{126.800, 126.720, 137.752, 191.346, 1.555, 0.010, 207.587, 151.653},
{128.082, 128.137, 141.633, 388.072, 1.548, 0.010, 207.612, 152.934},
{129.378, 129.612, 147.515, 588.203, 1.540, 0.010, 207.646, 154.229},
{130.689, 131.167, 155.497, 798.280, 1.531, 0.010, 207.692, 155.540},
{132.018, 132.824, 165.746, 1024.828, 1.521, 0.010, 207.751, 156.867},
{133.363, 134.593, 176.848, 1110.202, 1.509, 0.010, 207.825, 158.211},
{134.728, 136.465, 187.215, 1036.699, 1.496, 0.010, 207.918, 159.573},
{136.113, 138.451, 198.622, 1140.699, 1.481, 0.010, 208.032, 160.952},
{137.518, 140.582, 213.112, 1449.037, 1.464, 0.010, 208.169, 162.351},
{138.947, 142.893, 231.072, 1796.044, 1.445, 0.010, 208.334, 163.771},
{140.402, 145.422, 252.914, 2184.199, 1.424, 0.010, 208.531, 165.212},
{141.884, 148.212, 279.042, 2612.732, 1.401, 0.010, 208.765, 166.675},
{143.397, 151.310, 309.790, 3074.784, 1.374, 0.010, 209.040, 168.163},
{144.944, 154.763, 345.320, 3553.018, 1.344, 0.010, 209.365, 169.676},
{146.531, 158.618, 385.450, 4013.008, 1.311, 0.010, 209.746, 171.216},
{148.160, 162.912, 429.388, 4393.759, 1.274, 0.010, 210.193, 172.783},
{149.836, 167.665, 475.342, 4595.402, 1.233, 0.010, 210.716, 174.376},
{151.565, 172.865, 520.005, 4466.392, 1.186, 0.010, 211.327, 175.993},
{153.350, 178.445, 557.960, 3795.426, 1.135, 0.010, 212.038, 177.629},
{155.192, 184.257, 581.176, 2321.579, 1.078, 0.010, 212.862, 179.277},
{157.093, 190.047, 579.002, -217.355, 1.016, 0.010, 213.812, 180.923},
{159.047, 195.439, 539.241, -3976.090, 0.949, 0.010, 214.896, 182.550},
{161.046, 199.948, 450.905, -8833.634, 0.877, 0.010, 216.118, 184.132},
{163.077, 203.035, 308.644, -14226.104, 0.802, 0.010, 217.473, 185.645},
{165.119, 204.209, 117.441, -19120.260, 0.726, 0.010, 218.947, 187.057},
{167.151, 203.184, -102.509, -21995.032, 0.649, 0.010, 220.518, 188.346},
{169.150, 199.968, -321.569, -21905.953, 0.573, 0.010, 222.156, 189.493},
{171.099, 194.821, -514.707, -19313.834, 0.501, 0.010, 223.830, 190.490},
{172.980, 188.179, -664.222, -14951.526, 0.433, 0.010, 225.510, 191.337},
{174.786, 180.568, -761.093, -9687.101, 0.371, 0.010, 227.172, 192.044},
{176.511, 172.494, -807.437, -4634.327, 0.314, 0.010, 228.797, 192.622},
{178.155, 164.368, -812.569, -513.244, 0.262, 0.010, 230.373, 193.088},
{179.720, 156.484, -788.420, 2414.945, 0.216, 0.010, 231.894, 193.458},
{181.210, 149.022, -746.206, 4221.415, 0.175, 0.010, 233.356, 193.747},
{182.630, 142.073, -694.823, 5138.236, 0.138, 0.010, 234.759, 193.968},
{183.987, 135.668, -640.528, 5429.497, 0.106, 0.010, 236.106, 194.133},
{185.285, 129.795, -587.289, 5323.879, 0.077, 0.010, 237.398, 194.252},
{186.529, 124.422, -537.361, 4992.883, 0.052, 0.010, 238.640, 194.332},
{187.724, 119.503, -491.827, 4553.397, 0.030, 0.010, 239.834, 194.381},
{188.874, 114.993, -451.035, 4079.192, 0.010, 0.010, 240.984, 194.404},
{189.983, 110.844, -414.900, 3613.496, 6.276, 0.010, 242.092, 194.405},
{191.053, 107.013, -383.106, 3179.358, 6.261, 0.010, 243.162, 194.390},
{192.087, 103.461, -355.234, 2787.209, 6.248, 0.010, 244.196, 194.360},
{193.089, 100.152, -330.834, 2440.050, 6.236, 0.010, 245.197, 194.319},
{194.060, 97.058, -309.466, 2136.713, 6.226, 0.010, 246.166, 194.269},
{195.001, 94.150, -290.727, 1873.942, 6.218, 0.010, 247.106, 194.211},
{195.915, 91.408, -274.251, 1647.581, 6.210, 0.010, 248.018, 194.148},
{196.803, 88.811, -259.718, 1453.294, 6.204, 0.010, 248.903, 194.081},
{197.667, 86.342, -246.849, 1286.901, 6.199, 0.010, 249.764, 194.010},
{198.507, 83.988, -235.403, 1144.589, 6.195, 0.010, 250.601, 193.938},
{199.324, 81.736, -225.174, 1022.953, 6.191, 0.010, 251.415, 193.864},
{200.120, 79.577, -215.984, 919.020, 6.188, 0.010, 252.207, 193.790},
{200.895, 77.500, -207.682, 830.207, 6.186, 0.010, 252.978, 193.716},
{201.650, 75.498, -200.139, 754.296, 6.185, 0.010, 253.730, 193.642},
{202.385, 73.566, -193.245, 689.380, 6.184, 0.010, 254.462, 193.570},
{203.102, 71.697, -186.907, 633.820, 6.184, 0.010, 255.175, 193.499},
{203.801, 69.886, -181.044, 586.212, 6.184, 0.010, 255.871, 193.430},
{204.482, 68.131, -175.591, 545.339, 6.185, 0.010, 256.549, 193.363},
{205.147, 66.426, -170.490, 510.153, 6.186, 0.010, 257.210, 193.298},
{205.794, 64.769, -165.692, 479.741, 6.188, 0.010, 257.855, 193.236},
{206.426, 63.157, -161.159, 453.307, 6.190, 0.010, 258.483, 193.177},
{207.042, 61.589, -156.858, 430.154, 6.192, 0.010, 259.097, 193.120},
{207.642, 60.061, -152.761, 409.667, 6.194, 0.010, 259.695, 193.065},
{208.228, 58.572, -148.848, 391.308, 6.197, 0.010, 260.278, 193.014},
{208.799, 57.121, -145.102, 374.596, 6.199, 0.010, 260.847, 192.965},
{209.356, 55.706, -141.511, 359.115, 6.202, 0.010, 261.402, 192.920},
{209.900, 54.326, -138.066, 344.495, 6.206, 0.010, 261.944, 192.877},
{210.430, 52.978, -134.762, 330.415, 6.209, 0.010, 262.472, 192.836},
{210.946, 51.662, -131.596, 316.600, 6.212, 0.010, 262.988, 192.799},
{211.450, 50.376, -128.567, 302.818, 6.216, 0.010, 263.490, 192.764},
{211.941, 49.120, -125.679, 288.878, 6.219, 0.010, 263.980, 192.732},
{212.420, 47.890, -122.932, 274.626, 6.222, 0.010, 264.458, 192.702},
{212.887, 46.687, -120.333, 259.950, 6.226, 0.010, 264.924, 192.674},
{213.342, 45.508, -117.885, 244.771, 6.229, 0.010, 265.379, 192.649},
{213.785, 44.352, -115.595, 229.049, 6.233, 0.010, 265.822, 192.626},
{214.218, 43.218, -113.467, 212.775, 6.236, 0.010, 266.253, 192.605},
{214.639, 42.102, -111.507, 195.968, 6.240, 0.010, 266.674, 192.586},
{215.049, 41.005, -109.720, 178.681, 6.243, 0.010, 267.084, 192.568},
{215.448, 39.924, -108.111, 160.984, 6.246, 0.010, 267.482, 192.553},
{215.837, 38.857, -106.681, 142.977, 6.249, 0.010, 267.871, 192.539},
{216.215, 37.803, -105.433, 124.769, 6.252, 0.010, 268.249, 192.527},
{216.582, 36.759, -104.368, 106.490, 6.255, 0.010, 268.616, 192.516},
{216.939, 35.724, -103.485, 88.274, 6.257, 0.010, 268.973, 192.506},
{217.286, 34.697, -102.783, 70.266, 6.260, 0.010, 269.320, 192.497},
{217.623, 33.674, -102.257, 52.609, 6.262, 0.010, 269.657, 192.490},
{217.950, 32.655, -101.902, 35.445, 6.264, 0.010, 269.983, 192.483},
{218.266, 31.638, -101.713, 18.914, 6.266, 0.010, 270.299, 192.478},
{218.572, 30.621, -101.682, 3.146, 6.268, 0.010, 270.606, 192.473},
{218.868, 29.603, -101.799, -11.742, 6.270, 0.010, 270.902, 192.469},
{219.154, 28.583, -102.055, -25.639, 6.272, 0.010, 271.187, 192.465},
{219.430, 27.558, -102.440, -38.454, 6.273, 0.010, 271.463, 192.462},
{219.695, 26.529, -102.941, -50.109, 6.275, 0.010, 271.728, 192.460},
{219.950, 25.493, -103.547, -60.540, 6.276, 0.010, 271.983, 192.458},
{220.194, 24.451, -104.244, -69.702, 6.277, 0.010, 272.228, 192.456},
{220.428, 23.401, -105.019, -77.565, 6.278, 0.010, 272.462, 192.455},
{220.652, 22.342, -105.860, -84.115, 6.279, 0.010, 272.685, 192.453},
{220.865, 21.275, -106.754, -89.351, 6.279, 0.010, 272.898, 192.453},
{221.067, 20.198, -107.687, -93.286, 6.280, 0.010, 273.100, 192.452},
{221.258, 19.111, -108.646, -95.948, 6.281, 0.010, 273.291, 192.451},
{221.438, 18.015, -109.620, -97.373, 6.281, 0.010, 273.471, 192.451},
{221.607, 16.909, -110.596, -97.608, 6.282, 0.010, 273.640, 192.451},
{221.765, 15.793, -111.563, -96.708, 6.282, 0.010, 273.798, 192.451},
{221.912, 14.668, -112.510, -94.734, 6.282, 0.010, 273.945, 192.450},
{222.047, 13.534, -113.428, -91.754, 6.282, 0.010, 274.080, 192.450},
{222.171, 12.391, -114.306, -87.838, 6.283, 0.010, 274.204, 192.450},
{222.283, 11.254, -113.702, 60.391, 6.283, 0.010, 274.317, 192.450},
{222.385, 10.153, -110.068, 363.440, 6.283, 0.010, 274.418, 192.450},
{222.476, 9.105, -104.811, 525.668, 6.283, 0.010, 274.509, 192.450},
{222.557, 8.111, -99.453, 535.806, 6.283, 0.010, 274.590, 192.450},
{222.629, 7.171, -94.001, 545.235, 6.283, 0.010, 274.662, 192.450},
{222.692, 6.286, -88.462, 553.891, 6.283, 0.010, 274.725, 192.450},
{222.746, 5.458, -82.845, 561.734, 6.283, 0.010, 274.779, 192.450},
{222.793, 4.686, -77.157, 568.747, 6.283, 0.010, 274.826, 192.450},
{222.833, 3.972, -71.408, 574.928, 6.283, 0.010, 274.866, 192.450},
{222.866, 3.316, -65.605, 580.293, 6.283, 0.010, 274.899, 192.450},
{222.893, 2.718, -59.756, 584.874, 6.283, 0.010, 274.926, 192.450},
{222.915, 2.180, -53.869, 588.710, 6.283, 0.010, 274.948, 192.450},
{222.932, 1.700, -47.951, 591.852, 6.283, 0.010, 274.965, 192.450},
{222.945, 1.280, -42.007, 594.359, 6.283, 0.010, 274.978, 192.450},
{222.954, 0.920, -36.044, 596.295, 6.283, 0.010, 274.987, 192.450},
{222.960, 0.619, -30.067, 597.728, 6.283, 0.010, 274.993, 192.450},
{222.964, 0.378, -24.080, 598.733, 6.283, 0.010, 274.997, 192.450},
{222.966, 0.197, -18.086, 599.385, 6.283, 0.010, 274.999, 192.450},
{222.967, 0.076, -12.088, 599.759, 6.283, 0.010, 275.000, 192.450},
{222.967, 0.015, -6.089, 599.935, 0.000, 0.010, 275.000, 192.450},
{222.967, 0.000, -1.544, 454.432, 0.000, 0.010, 275.000, 192.450}};
double right_wheel[290][8] ={ 
{0.000, 0.060, 6.000, 600.000, 1.571, 0.010, 227.450, 24.999},
{0.001, 0.120, 6.000, -0.002, 1.571, 0.010, 227.450, 25.000},
{0.004, 0.270, 15.000, 899.988, 1.571, 0.010, 227.450, 25.003},
{0.009, 0.480, 20.999, 599.963, 1.571, 0.010, 227.450, 25.008},
{0.016, 0.750, 26.999, 599.914, 1.571, 0.010, 227.450, 25.015},
{0.027, 1.080, 32.997, 599.835, 1.571, 0.010, 227.450, 25.026},
{0.042, 1.470, 38.994, 599.717, 1.571, 0.010, 227.450, 25.041},
{0.061, 1.920, 44.990, 599.554, 1.571, 0.010, 227.450, 25.060},
{0.085, 2.430, 50.983, 599.337, 1.571, 0.010, 227.450, 25.084},
{0.115, 2.999, 56.974, 599.059, 1.571, 0.010, 227.450, 25.114},
{0.152, 3.629, 62.961, 598.714, 1.571, 0.010, 227.450, 25.151},
{0.195, 4.318, 68.944, 598.294, 1.571, 0.010, 227.450, 25.194},
{0.246, 5.068, 74.922, 597.793, 1.571, 0.010, 227.450, 25.244},
{0.304, 5.877, 80.894, 597.205, 1.571, 0.010, 227.450, 25.303},
{0.372, 6.745, 86.859, 596.525, 1.571, 0.010, 227.450, 25.371},
{0.449, 7.673, 92.816, 595.747, 1.571, 0.010, 227.450, 25.447},
{0.535, 8.661, 98.765, 594.867, 1.571, 0.010, 227.450, 25.534},
{0.632, 9.708, 104.704, 593.880, 1.571, 0.010, 227.450, 25.631},
{0.740, 10.814, 110.632, 592.785, 1.571, 0.010, 227.450, 25.739},
{0.860, 11.980, 116.548, 591.579, 1.571, 0.010, 227.450, 25.859},
{0.992, 13.174, 119.456, 290.884, 1.571, 0.010, 227.450, 25.991},
{1.136, 14.368, 119.362, -9.482, 1.571, 0.010, 227.450, 26.134},
{1.291, 15.561, 119.259, -10.219, 1.571, 0.010, 227.450, 26.290},
{1.459, 16.752, 119.150, -10.924, 1.571, 0.010, 227.450, 26.458},
{1.638, 17.942, 119.034, -11.595, 1.570, 0.010, 227.450, 26.637},
{1.830, 19.132, 118.912, -12.229, 1.570, 0.010, 227.450, 26.828},
{2.033, 20.319, 118.784, -12.824, 1.570, 0.010, 227.450, 27.031},
{2.248, 21.506, 118.650, -13.378, 1.570, 0.010, 227.451, 27.247},
{2.475, 22.691, 118.511, -13.888, 1.570, 0.010, 227.451, 27.473},
{2.713, 23.875, 118.367, -14.352, 1.570, 0.010, 227.451, 27.712},
{2.964, 25.057, 118.220, -14.768, 1.570, 0.010, 227.451, 27.963},
{3.226, 26.238, 118.068, -15.134, 1.570, 0.010, 227.451, 28.225},
{3.501, 27.417, 117.914, -15.449, 1.570, 0.010, 227.452, 28.499},
{3.786, 28.594, 117.757, -15.710, 1.570, 0.010, 227.452, 28.785},
{4.084, 29.770, 117.598, -15.915, 1.569, 0.010, 227.452, 29.083},
{4.394, 30.945, 117.437, -16.064, 1.569, 0.010, 227.453, 29.392},
{4.715, 32.117, 117.276, -16.154, 1.569, 0.010, 227.453, 29.714},
{5.048, 33.288, 117.114, -16.183, 1.569, 0.010, 227.454, 30.046},
{5.392, 34.458, 116.952, -16.151, 1.568, 0.010, 227.455, 30.391},
{5.749, 35.626, 116.792, -16.057, 1.568, 0.010, 227.456, 30.747},
{6.116, 36.792, 116.633, -15.898, 1.568, 0.010, 227.457, 31.115},
{6.496, 37.957, 116.476, -15.673, 1.567, 0.010, 227.458, 31.495},
{6.887, 39.120, 116.322, -15.383, 1.567, 0.010, 227.459, 31.886},
{7.290, 40.282, 116.172, -15.025, 1.567, 0.010, 227.461, 32.289},
{7.704, 41.442, 116.026, -14.600, 1.566, 0.010, 227.463, 32.703},
{8.130, 42.601, 115.885, -14.105, 1.566, 0.010, 227.465, 33.129},
{8.568, 43.759, 115.749, -13.542, 1.565, 0.010, 227.467, 33.567},
{9.017, 44.915, 115.620, -12.909, 1.565, 0.010, 227.470, 34.016},
{9.478, 46.070, 115.498, -12.207, 1.564, 0.010, 227.473, 34.477},
{9.950, 47.224, 115.384, -11.434, 1.563, 0.010, 227.476, 34.949},
{10.434, 48.376, 115.278, -10.591, 1.563, 0.010, 227.480, 35.433},
{10.929, 49.528, 115.181, -9.679, 1.562, 0.010, 227.484, 35.928},
{11.436, 50.679, 115.094, -8.696, 1.561, 0.010, 227.489, 36.435},
{11.954, 51.829, 115.018, -7.645, 1.561, 0.010, 227.494, 36.953},
{12.484, 52.979, 114.953, -6.525, 1.560, 0.010, 227.499, 37.483},
{13.025, 54.128, 114.899, -5.337, 1.559, 0.010, 227.506, 38.024},
{13.578, 55.276, 114.858, -4.082, 1.558, 0.010, 227.513, 38.577},
{14.142, 56.425, 114.831, -2.761, 1.557, 0.010, 227.520, 39.141},
{14.718, 57.573, 114.817, -1.375, 1.556, 0.010, 227.528, 39.717},
{15.305, 58.721, 114.818, 0.073, 1.555, 0.010, 227.537, 40.304},
{15.904, 59.869, 114.834, 1.583, 1.554, 0.010, 227.547, 40.902},
{16.514, 61.018, 114.865, 3.152, 1.553, 0.010, 227.558, 41.512},
{17.136, 62.167, 114.913, 4.778, 1.552, 0.010, 227.569, 42.134},
{17.769, 63.317, 114.977, 6.460, 1.550, 0.010, 227.582, 42.767},
{18.414, 64.468, 115.059, 8.193, 1.549, 0.010, 227.595, 43.411},
{19.070, 65.619, 115.159, 9.977, 1.548, 0.010, 227.610, 44.068},
{19.738, 66.772, 115.277, 11.806, 1.547, 0.010, 227.626, 44.735},
{20.417, 67.926, 115.414, 13.678, 1.545, 0.010, 227.642, 45.414},
{21.108, 69.082, 115.570, 15.590, 1.544, 0.010, 227.661, 46.105},
{21.810, 70.239, 115.745, 17.538, 1.543, 0.010, 227.680, 46.807},
{22.524, 71.399, 115.940, 19.516, 1.541, 0.010, 227.701, 47.520},
{23.250, 72.560, 116.156, 21.522, 1.540, 0.010, 227.723, 48.246},
{23.987, 73.724, 116.391, 23.550, 1.538, 0.010, 227.746, 48.983},
{24.736, 74.891, 116.647, 25.595, 1.537, 0.010, 227.771, 49.731},
{25.496, 76.060, 116.924, 27.652, 1.535, 0.010, 227.798, 50.491},
{26.269, 77.232, 117.221, 29.716, 1.533, 0.010, 227.826, 51.263},
{27.053, 78.407, 117.539, 31.780, 1.532, 0.010, 227.856, 52.047},
{27.849, 79.586, 117.877, 33.839, 1.530, 0.010, 227.888, 52.842},
{28.656, 80.768, 118.236, 35.886, 1.529, 0.010, 227.921, 53.649},
{29.476, 81.955, 118.615, 37.915, 1.527, 0.010, 227.957, 54.468},
{30.307, 83.145, 119.014, 39.919, 1.525, 0.010, 227.994, 55.298},
{31.151, 84.339, 119.433, 41.891, 1.524, 0.010, 228.033, 56.141},
{32.006, 85.538, 119.871, 43.823, 1.522, 0.010, 228.074, 56.995},
{32.873, 86.741, 120.328, 45.709, 1.520, 0.010, 228.117, 57.861},
{33.753, 87.949, 120.804, 47.540, 1.519, 0.010, 228.162, 58.740},
{34.645, 89.162, 121.297, 49.309, 1.517, 0.010, 228.209, 59.630},
{35.548, 90.380, 121.807, 51.007, 1.515, 0.010, 228.259, 60.533},
{36.464, 91.603, 122.333, 52.626, 1.514, 0.010, 228.310, 61.447},
{37.393, 92.832, 122.875, 54.159, 1.512, 0.010, 228.364, 62.374},
{38.333, 94.067, 123.431, 55.595, 1.511, 0.010, 228.419, 63.313},
{39.286, 95.307, 124.000, 56.927, 1.509, 0.010, 228.478, 64.264},
{40.252, 96.552, 124.581, 58.145, 1.508, 0.010, 228.538, 65.228},
{41.230, 97.804, 125.174, 59.240, 1.506, 0.010, 228.600, 66.204},
{42.221, 99.062, 125.776, 60.203, 1.505, 0.010, 228.665, 67.192},
{43.224, 100.326, 126.386, 61.025, 1.503, 0.010, 228.732, 68.193},
{44.240, 101.596, 127.003, 61.695, 1.502, 0.010, 228.801, 69.207},
{45.269, 102.872, 127.625, 62.203, 1.501, 0.010, 228.872, 70.233},
{46.310, 104.155, 128.251, 62.541, 1.500, 0.010, 228.945, 71.272},
{47.365, 105.443, 128.877, 62.696, 1.499, 0.010, 229.021, 72.324},
{48.432, 106.738, 129.504, 62.657, 1.498, 0.010, 229.098, 73.389},
{49.512, 108.010, 127.158, -234.558, 1.497, 0.010, 229.177, 74.466},
{50.604, 109.228, 121.822, -533.647, 1.496, 0.010, 229.259, 75.555},
{51.708, 110.393, 116.451, -537.108, 1.495, 0.010, 229.342, 76.656},
{52.823, 111.503, 111.041, -540.969, 1.494, 0.010, 229.426, 77.768},
{53.949, 112.559, 105.589, -545.213, 1.494, 0.010, 229.512, 78.890},
{55.084, 113.560, 100.091, -549.821, 1.493, 0.010, 229.600, 80.022},
{56.230, 114.505, 94.543, -554.772, 1.493, 0.010, 229.688, 81.164},
{57.383, 115.395, 88.943, -560.043, 1.493, 0.010, 229.778, 82.314},
{58.546, 116.228, 83.287, -565.607, 1.493, 0.010, 229.869, 83.473},
{59.716, 117.003, 77.572, -571.438, 1.493, 0.010, 229.960, 84.639},
{60.893, 117.721, 71.797, -577.506, 1.493, 0.010, 230.051, 85.813},
{62.077, 118.381, 65.959, -583.781, 1.493, 0.010, 230.143, 86.993},
{63.267, 118.981, 60.057, -590.228, 1.494, 0.010, 230.235, 88.180},
{64.462, 119.522, 54.089, -596.816, 1.494, 0.010, 230.327, 89.371},
{65.662, 120.003, 48.054, -603.508, 1.495, 0.010, 230.419, 90.568},
{66.866, 120.422, 41.951, -610.267, 1.495, 0.010, 230.510, 91.769},
{68.074, 120.780, 35.781, -617.056, 1.496, 0.010, 230.601, 92.973},
{69.285, 121.076, 29.542, -623.837, 1.497, 0.010, 230.691, 94.180},
{70.498, 121.308, 23.237, -630.571, 1.498, 0.010, 230.779, 95.390},
{71.713, 121.477, 16.864, -637.216, 1.499, 0.010, 230.867, 96.602},
{72.929, 121.611, 13.469, -339.541, 1.501, 0.010, 230.952, 97.815},
{74.146, 121.742, 13.068, -40.092, 1.502, 0.010, 231.037, 99.029},
{75.365, 121.868, 12.630, -43.827, 1.504, 0.010, 231.120, 100.245},
{76.585, 121.990, 12.154, -47.575, 1.505, 0.010, 231.201, 101.462},
{77.806, 122.106, 11.641, -51.335, 1.507, 0.010, 231.280, 102.681},
{79.028, 122.217, 11.090, -55.107, 1.509, 0.010, 231.357, 103.901},
{80.251, 122.322, 10.501, -58.889, 1.511, 0.010, 231.431, 105.122},
{81.475, 122.421, 9.874, -62.680, 1.512, 0.010, 231.504, 106.344},
{82.700, 122.513, 9.209, -66.477, 1.515, 0.010, 231.574, 107.567},
{83.926, 122.598, 8.506, -70.278, 1.517, 0.010, 231.642, 108.791},
{85.153, 122.676, 7.766, -74.080, 1.519, 0.010, 231.707, 110.016},
{86.381, 122.746, 6.987, -77.882, 1.521, 0.010, 231.769, 111.242},
{87.609, 122.807, 6.170, -81.679, 1.523, 0.010, 231.829, 112.468},
{88.837, 122.860, 5.315, -85.470, 1.526, 0.010, 231.886, 113.696},
{90.066, 122.905, 4.423, -89.251, 1.528, 0.010, 231.940, 114.924},
{91.296, 122.940, 3.493, -93.020, 1.530, 0.010, 231.992, 116.152},
{92.525, 122.965, 2.525, -96.774, 1.533, 0.010, 232.040, 117.381},
{93.755, 122.980, 1.520, -100.510, 1.535, 0.010, 232.086, 118.610},
{94.985, 122.985, 0.477, -104.227, 1.537, 0.010, 232.128, 119.839},
{96.215, 122.979, -0.602, -107.923, 1.540, 0.010, 232.168, 121.068},
{97.444, 122.962, -1.718, -111.597, 1.542, 0.010, 232.205, 122.297},
{98.674, 122.933, -2.870, -115.248, 1.544, 0.010, 232.238, 123.526},
{99.903, 122.892, -4.059, -118.876, 1.547, 0.010, 232.269, 124.754},
{101.131, 122.839, -5.284, -122.482, 1.549, 0.010, 232.297, 125.982},
{102.359, 122.774, -6.545, -126.068, 1.551, 0.010, 232.323, 127.210},
{103.586, 122.696, -7.841, -129.635, 1.553, 0.010, 232.345, 128.437},
{104.812, 122.604, -9.173, -133.186, 1.556, 0.010, 232.365, 129.662},
{106.037, 122.498, -10.540, -136.727, 1.558, 0.010, 232.383, 130.887},
{107.261, 122.379, -11.943, -140.260, 1.560, 0.010, 232.398, 132.111},
{108.483, 122.245, -13.381, -143.792, 1.561, 0.010, 232.410, 133.333},
{109.704, 122.097, -14.854, -147.329, 1.563, 0.010, 232.421, 134.554},
{110.923, 121.933, -16.363, -150.878, 1.565, 0.010, 232.429, 135.774},
{112.141, 121.754, -17.907, -154.446, 1.566, 0.010, 232.436, 136.991},
{113.356, 121.559, -19.487, -158.040, 1.567, 0.010, 232.441, 138.207},
{114.570, 121.348, -21.104, -161.668, 1.568, 0.010, 232.445, 139.420},
{115.781, 121.121, -22.758, -165.339, 1.569, 0.010, 232.447, 140.631},
{116.990, 120.876, -24.448, -169.060, 1.570, 0.010, 232.449, 141.840},
{118.196, 120.614, -26.176, -172.837, 1.570, 0.010, 232.450, 143.046},
{119.399, 120.335, -27.943, -176.675, 1.571, 0.010, 232.450, 144.250},
{120.599, 119.957, -37.733, -978.999, 1.571, 0.010, 232.450, 145.449},
{121.787, 118.756, -120.126, -8239.275, 1.570, 0.010, 232.451, 146.637},
{122.960, 117.375, -138.134, -1800.763, 1.568, 0.010, 232.453, 147.811},
{124.120, 116.016, -135.933, 220.064, 1.564, 0.010, 232.459, 148.971},
{125.267, 114.657, -135.847, 8.639, 1.560, 0.010, 232.469, 150.117},
{126.400, 113.279, -137.763, -191.602, 1.555, 0.010, 232.484, 151.250},
{127.518, 111.863, -141.646, -388.357, 1.548, 0.010, 232.505, 152.368},
{128.622, 110.388, -147.531, -588.533, 1.540, 0.010, 232.535, 153.472},
{129.711, 108.833, -155.518, -798.675, 1.531, 0.010, 232.572, 154.559},
{130.782, 107.175, -165.771, -1025.309, 1.521, 0.010, 232.620, 155.630},
{131.836, 105.377, -179.790, -1401.912, 1.509, 0.010, 232.678, 156.682},
{132.870, 103.386, -199.076, -1928.536, 1.496, 0.010, 232.749, 157.714},
{133.882, 101.161, -222.492, -2341.575, 1.481, 0.010, 232.831, 158.722},
{134.868, 98.671, -248.993, -2650.143, 1.464, 0.010, 232.928, 159.704},
{135.827, 95.882, -278.967, -2997.406, 1.445, 0.010, 233.039, 160.656},
{136.755, 92.753, -312.826, -3385.918, 1.424, 0.010, 233.164, 161.575},
{137.647, 89.244, -350.975, -3814.888, 1.401, 0.010, 233.305, 162.457},
{138.500, 85.306, -393.750, -4277.471, 1.374, 0.010, 233.460, 163.295},
{139.309, 80.893, -441.314, -4756.376, 1.344, 0.010, 233.630, 164.086},
{140.069, 75.958, -493.485, -5217.165, 1.311, 0.010, 233.812, 164.824},
{140.773, 70.463, -549.473, -5598.783, 1.274, 0.010, 234.005, 165.501},
{141.417, 64.389, -607.487, -5801.374, 1.233, 0.010, 234.206, 166.113},
{141.995, 57.746, -664.218, -5673.148, 1.186, 0.010, 234.409, 166.654},
{142.501, 50.604, -714.244, -5002.571, 1.135, 0.010, 234.611, 167.118},
{142.932, 43.109, -749.526, -3528.241, 1.078, 0.010, 234.803, 167.504},
{143.287, 35.515, -759.400, -987.406, 1.016, 0.010, 234.980, 167.812},
{143.569, 28.198, -731.648, 2775.258, 0.949, 0.010, 235.136, 168.046},
{143.785, 21.646, -655.259, 7638.858, 0.877, 0.010, 235.268, 168.218},
{143.949, 16.397, -524.871, 13038.875, 0.802, 0.010, 235.377, 168.340},
{144.079, 12.942, -345.468, 17940.279, 0.726, 0.010, 235.471, 168.430},
{144.195, 11.599, -134.362, 21110.544, 0.649, 0.010, 235.560, 168.504},
{144.319, 12.417, 81.848, 21620.993, 0.573, 0.010, 235.662, 168.575},
{144.471, 15.169, 275.175, 19332.789, 0.501, 0.010, 235.793, 168.652},
{144.665, 19.417, 424.806, 14963.014, 0.433, 0.010, 235.966, 168.739},
{144.911, 24.634, 521.715, 9690.914, 0.371, 0.010, 236.193, 168.835},
{145.214, 30.314, 568.035, 4632.044, 0.314, 0.010, 236.479, 168.937},
{145.575, 36.045, 573.107, 507.148, 0.262, 0.010, 236.824, 169.038},
{145.990, 41.534, 548.879, -2422.753, 0.216, 0.010, 237.228, 169.136},
{146.456, 46.600, 506.585, -4229.437, 0.175, 0.010, 237.685, 169.227},
{146.968, 51.151, 455.129, -5145.606, 0.138, 0.010, 238.191, 169.306},
{147.519, 55.159, 400.770, -5435.836, 0.106, 0.010, 238.738, 169.373},
{148.106, 58.634, 347.479, -5329.103, 0.077, 0.010, 239.322, 169.426},
{148.722, 61.609, 297.509, -4997.082, 0.052, 0.010, 239.937, 169.466},
{149.363, 64.128, 251.941, -4556.709, 0.030, 0.010, 240.578, 169.492},
{150.025, 66.240, 211.124, -4081.784, 0.010, 0.010, 241.240, 169.505},
{150.705, 67.989, 174.968, -3615.514, 6.276, 0.010, 241.920, 169.506},
{151.399, 69.421, 143.159, -3180.916, 6.261, 0.010, 242.614, 169.496},
{152.105, 70.574, 115.275, -2788.420, 6.248, 0.010, 243.319, 169.476},
{152.820, 71.482, 90.865, -2440.986, 6.236, 0.010, 244.034, 169.446},
{153.542, 72.177, 69.491, -2137.442, 6.226, 0.010, 244.754, 169.409},
{154.269, 72.685, 50.746, -1874.506, 6.218, 0.010, 245.480, 169.364},
{154.999, 73.027, 34.266, -1648.024, 6.210, 0.010, 246.208, 169.314},
{155.731, 73.225, 19.729, -1453.637, 6.204, 0.010, 246.938, 169.258},
{156.464, 73.293, 6.857, -1287.171, 6.199, 0.010, 247.669, 169.199},
{157.196, 73.247, -4.591, -1144.800, 6.195, 0.010, 248.399, 169.135},
{157.927, 73.099, -14.822, -1023.119, 6.191, 0.010, 249.127, 169.069},
{158.656, 72.859, -24.013, -919.148, 6.188, 0.010, 249.852, 169.001},
{159.381, 72.536, -32.316, -830.307, 6.186, 0.010, 250.574, 168.932},
{160.103, 72.137, -39.860, -754.374, 6.185, 0.010, 251.292, 168.862},
{160.819, 71.670, -46.754, -689.439, 6.184, 0.010, 252.005, 168.791},
{161.531, 71.139, -53.093, -633.866, 6.184, 0.010, 252.713, 168.721},
{162.236, 70.549, -58.956, -586.245, 6.184, 0.010, 253.415, 168.651},
{162.935, 69.905, -64.409, -545.363, 6.185, 0.010, 254.111, 168.583},
{163.628, 69.210, -69.511, -510.169, 6.186, 0.010, 254.800, 168.515},
{164.312, 68.467, -74.308, -479.751, 6.188, 0.010, 255.481, 168.450},
{164.989, 67.678, -78.841, -453.313, 6.190, 0.010, 256.155, 168.386},
{165.657, 66.847, -83.143, -430.156, 6.192, 0.010, 256.821, 168.324},
{166.317, 65.975, -87.240, -409.667, 6.194, 0.010, 257.478, 168.264},
{166.968, 65.063, -91.153, -391.303, 6.197, 0.010, 258.126, 168.207},
{167.609, 64.114, -94.899, -374.592, 6.199, 0.010, 258.765, 168.153},
{168.240, 63.129, -98.490, -359.108, 6.202, 0.010, 259.394, 168.101},
{168.861, 62.110, -101.935, -344.487, 6.206, 0.010, 260.013, 168.052},
{169.472, 61.057, -105.239, -330.407, 6.209, 0.010, 260.622, 168.005},
{170.072, 59.973, -108.405, -316.592, 6.212, 0.010, 261.220, 167.962},
{170.660, 58.859, -111.433, -302.810, 6.216, 0.010, 261.807, 167.921},
{171.237, 57.716, -114.321, -288.870, 6.219, 0.010, 262.383, 167.883},
{171.803, 56.545, -117.068, -274.619, 6.222, 0.010, 262.947, 167.848},
{172.356, 55.348, -119.667, -259.942, 6.226, 0.010, 263.500, 167.815},
{172.898, 54.127, -122.115, -244.766, 6.229, 0.010, 264.040, 167.785},
{173.426, 52.883, -124.405, -229.044, 6.233, 0.010, 264.568, 167.757},
{173.943, 51.618, -126.533, -212.770, 6.236, 0.010, 265.084, 167.732},
{174.446, 50.333, -128.492, -195.966, 6.240, 0.010, 265.587, 167.709},
{174.936, 49.030, -130.279, -178.677, 6.243, 0.010, 266.077, 167.689},
{175.413, 47.711, -131.889, -160.984, 6.246, 0.010, 266.553, 167.670},
{175.877, 46.378, -133.319, -142.975, 6.249, 0.010, 267.017, 167.654},
{176.327, 45.032, -134.567, -124.770, 6.252, 0.010, 267.467, 167.639},
{176.764, 43.676, -135.631, -106.490, 6.255, 0.010, 267.904, 167.626},
{177.187, 42.311, -136.514, -88.276, 6.257, 0.010, 268.326, 167.614},
{177.597, 40.939, -137.217, -70.268, 6.260, 0.010, 268.736, 167.604},
{177.992, 39.561, -137.743, -52.610, 6.262, 0.010, 269.131, 167.595},
{178.374, 38.180, -138.097, -35.448, 6.264, 0.010, 269.513, 167.588},
{178.742, 36.798, -138.287, -18.917, 6.266, 0.010, 269.881, 167.581},
{179.096, 35.414, -138.318, -3.147, 6.268, 0.010, 270.235, 167.575},
{179.437, 34.032, -138.201, 11.739, 6.270, 0.010, 270.575, 167.571},
{179.763, 32.653, -137.944, 25.637, 6.272, 0.010, 270.902, 167.567},
{180.076, 31.277, -137.560, 38.452, 6.273, 0.010, 271.215, 167.563},
{180.375, 29.907, -137.059, 50.106, 6.275, 0.010, 271.514, 167.561},
{180.660, 28.542, -136.453, 60.538, 6.276, 0.010, 271.799, 167.558},
{180.932, 27.185, -135.756, 69.701, 6.277, 0.010, 272.071, 167.556},
{181.191, 25.835, -134.981, 77.564, 6.278, 0.010, 272.329, 167.555},
{181.436, 24.493, -134.140, 84.113, 6.279, 0.010, 272.574, 167.554},
{181.667, 23.161, -133.246, 89.350, 6.279, 0.010, 272.806, 167.553},
{181.886, 21.838, -132.313, 93.286, 6.280, 0.010, 273.024, 167.552},
{182.091, 20.524, -131.354, 95.947, 6.281, 0.010, 273.229, 167.552},
{182.283, 19.221, -130.380, 97.373, 6.281, 0.010, 273.422, 167.551},
{182.462, 17.927, -129.404, 97.608, 6.282, 0.010, 273.601, 167.551},
{182.629, 16.642, -128.437, 96.707, 6.282, 0.010, 273.767, 167.551},
{182.782, 15.367, -127.490, 94.734, 6.282, 0.010, 273.921, 167.550},
{182.923, 14.102, -126.572, 91.753, 6.282, 0.010, 274.062, 167.550},
{183.052, 12.845, -125.694, 87.839, 6.283, 0.010, 274.190, 167.550},
{183.168, 11.611, -123.386, 230.728, 6.283, 0.010, 274.306, 167.550},
{183.272, 10.430, -118.110, 527.680, 6.283, 0.010, 274.411, 167.550},
{183.365, 9.316, -111.366, 674.332, 6.283, 0.010, 274.504, 167.550},
{183.448, 8.269, -104.724, 664.194, 6.283, 0.010, 274.587, 167.550},
{183.521, 7.287, -98.177, 654.765, 6.283, 0.010, 274.660, 167.550},
{183.585, 6.370, -91.716, 646.109, 6.283, 0.010, 274.723, 167.550},
{183.640, 5.516, -85.333, 638.266, 6.283, 0.010, 274.778, 167.550},
{183.687, 4.726, -79.020, 631.253, 6.283, 0.010, 274.826, 167.550},
{183.727, 3.999, -72.770, 625.072, 6.283, 0.010, 274.866, 167.550},
{183.760, 3.333, -66.573, 619.707, 6.283, 0.010, 274.899, 167.550},
{183.788, 2.729, -60.421, 615.126, 6.283, 0.010, 274.926, 167.550},
{183.809, 2.186, -54.308, 611.290, 6.283, 0.010, 274.948, 167.550},
{183.827, 1.703, -48.227, 608.148, 6.283, 0.010, 274.965, 167.550},
{183.839, 1.282, -42.171, 605.641, 6.283, 0.010, 274.978, 167.550},
{183.849, 0.920, -36.133, 603.705, 6.283, 0.010, 274.987, 167.550},
{183.855, 0.619, -30.111, 602.272, 6.283, 0.010, 274.993, 167.550},
{183.859, 0.378, -24.098, 601.267, 6.283, 0.010, 274.997, 167.550},
{183.860, 0.197, -18.092, 600.615, 6.283, 0.010, 274.999, 167.550},
{183.861, 0.076, -12.090, 600.241, 6.283, 0.010, 275.000, 167.550},
{183.861, 0.015, -6.089, 600.065, 0.000, 0.010, 275.000, 167.550},
{183.861, 0.000, -1.544, 454.449, 0.000, 0.010, 275.000, 167.550}};
#endif