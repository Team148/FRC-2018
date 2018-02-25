#ifndef FromRightScale_ToRightFirstCubePath_H
#define FromRightScale_ToRightFirstCubePath_H
int num_index = 154;
double left_wheel[154][8] ={ 
{0.000, 0.059, 5.939, 593.909, 0.000, 0.010, 0.000, 12.000},
{0.001, 0.119, 5.939, 0.000, 0.000, 0.010, 0.001, 12.000},
{0.004, 0.267, 14.848, 890.864, 0.000, 0.010, 0.004, 12.000},
{0.009, 0.475, 20.787, 593.909, 0.000, 0.010, 0.009, 12.000},
{0.016, 0.742, 26.726, 593.909, 0.000, 0.010, 0.016, 12.000},
{0.027, 1.069, 32.665, 593.909, 0.000, 0.010, 0.027, 12.000},
{0.042, 1.455, 38.604, 593.909, 0.000, 0.010, 0.042, 12.000},
{0.061, 1.901, 44.543, 593.909, 0.000, 0.010, 0.061, 12.000},
{0.085, 2.405, 50.482, 593.909, 0.000, 0.010, 0.085, 12.000},
{0.114, 2.970, 56.421, 593.909, 0.000, 0.010, 0.114, 12.000},
{0.150, 3.593, 62.360, 593.909, 0.000, 0.010, 0.150, 12.000},
{0.193, 4.276, 68.300, 593.909, 0.000, 0.010, 0.193, 12.000},
{0.243, 5.019, 74.239, 593.909, 0.000, 0.010, 0.243, 12.000},
{0.301, 5.820, 80.178, 593.909, 0.000, 0.010, 0.301, 12.000},
{0.368, 6.681, 86.117, 593.909, 0.000, 0.010, 0.368, 12.000},
{0.444, 7.602, 92.056, 593.909, 0.000, 0.010, 0.444, 12.000},
{0.530, 8.582, 97.995, 593.909, 0.000, 0.010, 0.530, 12.000},
{0.626, 9.621, 103.934, 593.909, 0.000, 0.010, 0.626, 12.000},
{0.733, 10.720, 109.873, 593.909, 0.000, 0.010, 0.733, 12.000},
{0.852, 11.878, 115.812, 593.909, 0.000, 0.010, 0.852, 12.000},
{0.983, 13.066, 118.782, 296.955, 0.000, 0.010, 0.983, 12.000},
{1.125, 14.254, 118.782, 0.000, 0.000, 0.010, 1.125, 12.000},
{1.280, 15.442, 118.782, -0.000, 0.000, 0.010, 1.280, 12.000},
{1.446, 16.629, 118.782, -0.000, 0.000, 0.010, 1.446, 12.000},
{1.624, 17.817, 118.782, -0.000, 0.000, 0.010, 1.624, 12.000},
{1.814, 19.005, 118.782, 0.000, 0.000, 0.010, 1.814, 12.000},
{2.016, 20.193, 118.782, -0.000, 0.000, 0.010, 2.016, 12.000},
{2.230, 21.381, 118.782, 0.000, 0.000, 0.010, 2.230, 12.000},
{2.456, 22.569, 118.782, 0.000, 0.000, 0.010, 2.456, 12.000},
{2.693, 23.756, 118.782, 0.000, 0.000, 0.010, 2.693, 12.000},
{2.943, 24.944, 118.782, 0.000, 0.000, 0.010, 2.943, 12.000},
{3.204, 26.132, 118.782, -0.000, 0.000, 0.010, 3.204, 12.000},
{3.477, 27.320, 118.782, 0.000, 0.000, 0.010, 3.477, 12.000},
{3.762, 28.508, 118.782, -0.000, 0.000, 0.010, 3.762, 12.000},
{4.059, 29.695, 118.782, 0.000, 0.000, 0.010, 4.059, 12.000},
{4.368, 30.883, 118.782, 0.000, 0.000, 0.010, 4.368, 12.000},
{4.689, 32.071, 118.782, -0.000, 0.000, 0.010, 4.689, 12.000},
{5.022, 33.259, 118.782, 0.000, 0.000, 0.010, 5.022, 12.000},
{5.366, 34.447, 118.782, -0.000, 0.000, 0.010, 5.366, 12.000},
{5.722, 35.635, 118.782, 0.000, 0.000, 0.010, 5.722, 12.000},
{6.091, 36.822, 118.782, -0.000, 0.000, 0.010, 6.091, 12.000},
{6.471, 38.010, 118.782, -0.000, 0.000, 0.010, 6.471, 12.000},
{6.863, 39.198, 118.782, 0.000, 0.000, 0.010, 6.863, 12.000},
{7.266, 40.386, 118.782, -0.000, 0.000, 0.010, 7.266, 12.000},
{7.682, 41.574, 118.782, 0.000, 0.000, 0.010, 7.682, 12.000},
{8.110, 42.761, 118.782, 0.000, 0.000, 0.010, 8.110, 12.000},
{8.549, 43.949, 118.782, -0.000, 0.000, 0.010, 8.549, 12.000},
{9.001, 45.137, 118.782, 0.000, 0.000, 0.010, 9.001, 12.000},
{9.464, 46.325, 118.782, 0.000, 0.000, 0.010, 9.464, 12.000},
{9.939, 47.513, 118.782, 0.000, 0.000, 0.010, 9.939, 12.000},
{10.426, 48.701, 118.782, -0.000, 0.000, 0.010, 10.426, 12.000},
{10.925, 49.888, 118.782, -0.000, 0.000, 0.010, 10.925, 12.000},
{11.436, 51.076, 118.782, 0.000, 0.000, 0.010, 11.436, 12.000},
{11.958, 52.264, 118.782, -0.000, 0.000, 0.010, 11.958, 12.000},
{12.493, 53.452, 118.782, 0.000, 0.000, 0.010, 12.493, 12.000},
{13.039, 54.640, 118.782, 0.000, 0.000, 0.010, 13.039, 12.000},
{13.598, 55.827, 118.782, -0.000, 0.000, 0.010, 13.598, 12.000},
{14.167, 56.986, 115.812, -296.955, 0.000, 0.010, 14.167, 12.000},
{14.748, 58.084, 109.873, -593.909, 0.000, 0.010, 14.748, 12.000},
{15.344, 59.553, 146.822, 3694.909, 6.283, 0.010, 15.344, 12.000},
{15.973, 62.879, 332.604, 18578.171, 6.281, 0.010, 15.973, 11.999},
{16.636, 66.299, 342.054, 944.964, 6.276, 0.010, 16.636, 11.996},
{17.331, 69.563, 326.385, -1566.834, 6.270, 0.010, 17.331, 11.989},
{18.058, 72.660, 309.695, -1668.996, 6.261, 0.010, 18.058, 11.976},
{18.814, 75.578, 291.811, -1788.452, 6.251, 0.010, 18.813, 11.956},
{19.597, 78.304, 272.547, -1926.427, 6.239, 0.010, 19.596, 11.927},
{20.405, 80.821, 251.729, -2081.780, 6.226, 0.010, 20.403, 11.886},
{21.236, 83.113, 229.220, -2250.916, 6.211, 0.010, 21.232, 11.832},
{22.088, 85.162, 204.941, -2427.829, 6.195, 0.010, 22.081, 11.764},
{22.957, 86.951, 178.898, -2604.322, 6.178, 0.010, 22.947, 11.680},
{23.842, 88.463, 151.193, -2770.498, 6.160, 0.010, 23.825, 11.579},
{24.739, 89.684, 122.038, -2915.506, 6.141, 0.010, 24.714, 11.460},
{25.645, 90.601, 91.753, -3028.519, 6.121, 0.010, 25.610, 11.323},
{26.557, 91.209, 60.754, -3099.844, 6.101, 0.010, 26.509, 11.167},
{27.472, 91.504, 29.534, -3122.010, 6.081, 0.010, 27.407, 10.993},
{28.387, 91.490, -1.372, -3090.650, 6.062, 0.010, 28.301, 10.801},
{29.298, 91.153, -33.730, -3235.779, 6.042, 0.010, 29.189, 10.592},
{30.203, 90.507, -64.652, -3092.174, 6.023, 0.010, 30.065, 10.367},
{31.099, 89.593, -91.372, -2672.005, 6.005, 0.010, 30.929, 10.129},
{31.983, 88.434, -115.863, -2449.123, 5.987, 0.010, 31.777, 9.878},
{32.854, 87.055, -137.877, -2201.366, 5.970, 0.010, 32.607, 9.617},
{33.709, 85.483, -157.271, -1939.429, 5.955, 0.010, 33.419, 9.347},
{34.546, 83.743, -174.005, -1673.367, 5.940, 0.010, 34.209, 9.071},
{35.365, 81.861, -188.123, -1411.874, 5.927, 0.010, 34.979, 8.791},
{36.164, 79.864, -199.742, -1161.857, 5.915, 0.010, 35.725, 8.508},
{36.941, 77.774, -209.025, -928.286, 5.904, 0.010, 36.449, 8.224},
{37.697, 75.612, -216.168, -714.280, 5.895, 0.010, 37.151, 7.941},
{38.431, 73.398, -221.381, -521.354, 5.887, 0.010, 37.829, 7.661},
{39.143, 71.150, -224.879, -349.758, 5.880, 0.010, 38.484, 7.384},
{39.832, 68.881, -226.867, -198.837, 5.875, 0.010, 39.117, 7.112},
{40.498, 66.605, -227.541, -67.381, 5.870, 0.010, 39.728, 6.846},
{41.141, 64.335, -227.080, 46.085, 5.867, 0.010, 40.317, 6.587},
{41.762, 62.078, -225.649, 143.063, 5.865, 0.010, 40.884, 6.336},
{42.360, 59.844, -223.400, 224.926, 5.864, 0.010, 41.431, 6.092},
{42.937, 57.639, -220.472, 292.810, 5.864, 0.010, 41.957, 5.858},
{43.491, 55.469, -216.996, 347.576, 5.864, 0.010, 42.464, 5.632},
{44.025, 53.355, -211.450, 554.631, 5.866, 0.010, 42.952, 5.415},
{44.538, 51.326, -202.910, 854.038, 5.868, 0.010, 43.421, 5.208},
{45.032, 49.393, -193.289, 962.052, 5.871, 0.010, 43.873, 5.009},
{45.508, 47.554, -183.882, 940.671, 5.874, 0.010, 44.309, 4.819},
{45.966, 45.807, -174.736, 914.678, 5.878, 0.010, 44.730, 4.638},
{46.407, 44.148, -165.892, 884.368, 5.882, 0.010, 45.136, 4.465},
{46.833, 42.574, -157.392, 849.990, 5.887, 0.010, 45.529, 4.300},
{47.244, 41.081, -149.274, 811.784, 5.892, 0.010, 45.908, 4.142},
{47.640, 39.666, -141.574, 770.020, 5.897, 0.010, 46.275, 3.991},
{48.024, 38.322, -134.324, 725.012, 5.902, 0.010, 46.630, 3.848},
{48.394, 37.047, -127.553, 677.130, 5.907, 0.010, 46.974, 3.711},
{48.752, 35.834, -121.285, 626.800, 5.912, 0.010, 47.308, 3.580},
{49.099, 34.679, -115.540, 574.501, 5.917, 0.010, 47.632, 3.455},
{49.435, 33.575, -110.332, 520.750, 5.922, 0.010, 47.945, 3.336},
{49.760, 32.518, -105.671, 466.092, 5.927, 0.010, 48.250, 3.222},
{50.075, 31.503, -101.560, 411.084, 5.932, 0.010, 48.545, 3.113},
{50.380, 30.523, -97.997, 356.280, 5.937, 0.010, 48.832, 3.009},
{50.676, 29.573, -94.975, 302.216, 5.941, 0.010, 49.111, 2.909},
{50.963, 28.648, -92.481, 249.397, 5.946, 0.010, 49.381, 2.813},
{51.240, 27.743, -90.498, 198.290, 5.950, 0.010, 49.643, 2.722},
{51.509, 26.853, -89.005, 149.315, 5.953, 0.010, 49.897, 2.635},
{51.768, 25.974, -87.977, 102.841, 5.957, 0.010, 50.143, 2.551},
{52.019, 25.100, -87.385, 59.183, 5.960, 0.010, 50.381, 2.471},
{52.262, 24.228, -87.199, 18.603, 5.963, 0.010, 50.610, 2.394},
{52.495, 23.354, -87.386, -18.688, 5.966, 0.010, 50.832, 2.321},
{52.720, 22.475, -87.911, -52.531, 5.968, 0.010, 51.046, 2.251},
{52.936, 21.587, -88.739, -82.810, 5.971, 0.010, 51.251, 2.185},
{53.143, 20.689, -89.834, -109.452, 5.973, 0.010, 51.448, 2.121},
{53.340, 19.777, -91.158, -132.422, 5.974, 0.010, 51.636, 2.061},
{53.529, 18.851, -92.675, -151.721, 5.976, 0.010, 51.816, 2.004},
{53.708, 17.907, -94.349, -167.380, 5.977, 0.010, 51.987, 1.950},
{53.877, 16.946, -96.144, -179.456, 5.978, 0.010, 52.148, 1.899},
{54.037, 15.965, -98.024, -188.034, 5.979, 0.010, 52.301, 1.851},
{54.187, 14.966, -99.956, -193.220, 5.980, 0.010, 52.444, 1.806},
{54.326, 13.947, -101.908, -195.143, 5.981, 0.010, 52.577, 1.765},
{54.455, 12.908, -103.847, -193.947, 5.981, 0.010, 52.700, 1.726},
{54.574, 11.851, -105.745, -189.797, 5.982, 0.010, 52.813, 1.691},
{54.682, 10.792, -105.915, -16.979, 5.982, 0.010, 52.916, 1.659},
{54.779, 9.761, -103.075, 284.014, 5.982, 0.010, 53.009, 1.630},
{54.867, 8.773, -98.818, 425.644, 5.983, 0.010, 53.093, 1.604},
{54.945, 7.829, -94.346, 447.178, 5.983, 0.010, 53.168, 1.581},
{55.015, 6.933, -89.669, 467.694, 5.983, 0.010, 53.234, 1.561},
{55.076, 6.085, -84.800, 486.905, 5.983, 0.010, 53.292, 1.543},
{55.128, 5.287, -79.754, 504.599, 5.983, 0.010, 53.343, 1.527},
{55.174, 4.542, -74.548, 520.632, 5.983, 0.010, 53.386, 1.514},
{55.212, 3.850, -69.199, 534.921, 5.983, 0.010, 53.423, 1.502},
{55.244, 3.212, -63.725, 547.435, 5.983, 0.010, 53.454, 1.493},
{55.271, 2.631, -58.143, 558.191, 5.983, 0.010, 53.479, 1.485},
{55.292, 2.106, -52.470, 567.245, 5.983, 0.010, 53.499, 1.479},
{55.308, 1.639, -46.723, 574.686, 5.983, 0.010, 53.515, 1.474},
{55.321, 1.230, -40.917, 580.633, 5.983, 0.010, 53.526, 1.470},
{55.329, 0.879, -35.065, 585.225, 5.983, 0.010, 53.535, 1.468},
{55.335, 0.587, -29.179, 588.620, 5.983, 0.010, 53.540, 1.466},
{55.339, 0.355, -23.269, 590.989, 5.983, 0.010, 53.544, 1.465},
{55.341, 0.181, -17.344, 592.513, 5.983, 0.010, 53.545, 1.464},
{55.341, 0.067, -11.410, 593.377, 5.983, 0.010, 53.546, 1.464},
{55.341, 0.013, -5.472, 593.773, 5.983, 0.010, 53.546, 1.464},
{55.341, 0.000, -1.251, 422.072, 5.983, 0.010, 53.546, 1.464}};
double right_wheel[154][8] ={ 
{0.000, 0.059, 5.939, 593.909, 0.000, 0.010, 0.000, -12.000},
{0.001, 0.119, 5.939, 0.000, 0.000, 0.010, 0.001, -12.000},
{0.004, 0.267, 14.848, 890.864, 0.000, 0.010, 0.004, -12.000},
{0.009, 0.475, 20.787, 593.909, 0.000, 0.010, 0.009, -12.000},
{0.016, 0.742, 26.726, 593.909, 0.000, 0.010, 0.016, -12.000},
{0.027, 1.069, 32.665, 593.909, 0.000, 0.010, 0.027, -12.000},
{0.042, 1.455, 38.604, 593.909, 0.000, 0.010, 0.042, -12.000},
{0.061, 1.901, 44.543, 593.909, 0.000, 0.010, 0.061, -12.000},
{0.085, 2.405, 50.482, 593.909, 0.000, 0.010, 0.085, -12.000},
{0.114, 2.970, 56.421, 593.909, 0.000, 0.010, 0.114, -12.000},
{0.150, 3.593, 62.360, 593.909, 0.000, 0.010, 0.150, -12.000},
{0.193, 4.276, 68.300, 593.909, 0.000, 0.010, 0.193, -12.000},
{0.243, 5.019, 74.239, 593.909, 0.000, 0.010, 0.243, -12.000},
{0.301, 5.820, 80.178, 593.909, 0.000, 0.010, 0.301, -12.000},
{0.368, 6.681, 86.117, 593.909, 0.000, 0.010, 0.368, -12.000},
{0.444, 7.602, 92.056, 593.909, 0.000, 0.010, 0.444, -12.000},
{0.530, 8.582, 97.995, 593.909, 0.000, 0.010, 0.530, -12.000},
{0.626, 9.621, 103.934, 593.909, 0.000, 0.010, 0.626, -12.000},
{0.733, 10.720, 109.873, 593.909, 0.000, 0.010, 0.733, -12.000},
{0.852, 11.878, 115.812, 593.909, 0.000, 0.010, 0.852, -12.000},
{0.983, 13.066, 118.782, 296.955, 0.000, 0.010, 0.983, -12.000},
{1.125, 14.254, 118.782, 0.000, 0.000, 0.010, 1.125, -12.000},
{1.280, 15.442, 118.782, -0.000, 0.000, 0.010, 1.280, -12.000},
{1.446, 16.629, 118.782, -0.000, 0.000, 0.010, 1.446, -12.000},
{1.624, 17.817, 118.782, -0.000, 0.000, 0.010, 1.624, -12.000},
{1.814, 19.005, 118.782, 0.000, 0.000, 0.010, 1.814, -12.000},
{2.016, 20.193, 118.782, -0.000, 0.000, 0.010, 2.016, -12.000},
{2.230, 21.381, 118.782, 0.000, 0.000, 0.010, 2.230, -12.000},
{2.456, 22.569, 118.782, 0.000, 0.000, 0.010, 2.456, -12.000},
{2.693, 23.756, 118.782, 0.000, 0.000, 0.010, 2.693, -12.000},
{2.943, 24.944, 118.782, 0.000, 0.000, 0.010, 2.943, -12.000},
{3.204, 26.132, 118.782, -0.000, 0.000, 0.010, 3.204, -12.000},
{3.477, 27.320, 118.782, 0.000, 0.000, 0.010, 3.477, -12.000},
{3.762, 28.508, 118.782, -0.000, 0.000, 0.010, 3.762, -12.000},
{4.059, 29.695, 118.782, 0.000, 0.000, 0.010, 4.059, -12.000},
{4.368, 30.883, 118.782, 0.000, 0.000, 0.010, 4.368, -12.000},
{4.689, 32.071, 118.782, -0.000, 0.000, 0.010, 4.689, -12.000},
{5.022, 33.259, 118.782, 0.000, 0.000, 0.010, 5.022, -12.000},
{5.366, 34.447, 118.782, -0.000, 0.000, 0.010, 5.366, -12.000},
{5.722, 35.635, 118.782, 0.000, 0.000, 0.010, 5.722, -12.000},
{6.091, 36.822, 118.782, -0.000, 0.000, 0.010, 6.091, -12.000},
{6.471, 38.010, 118.782, -0.000, 0.000, 0.010, 6.471, -12.000},
{6.863, 39.198, 118.782, 0.000, 0.000, 0.010, 6.863, -12.000},
{7.266, 40.386, 118.782, -0.000, 0.000, 0.010, 7.266, -12.000},
{7.682, 41.574, 118.782, 0.000, 0.000, 0.010, 7.682, -12.000},
{8.110, 42.761, 118.782, 0.000, 0.000, 0.010, 8.110, -12.000},
{8.549, 43.949, 118.782, -0.000, 0.000, 0.010, 8.549, -12.000},
{9.001, 45.137, 118.782, 0.000, 0.000, 0.010, 9.001, -12.000},
{9.464, 46.325, 118.782, 0.000, 0.000, 0.010, 9.464, -12.000},
{9.939, 47.513, 118.782, 0.000, 0.000, 0.010, 9.939, -12.000},
{10.426, 48.701, 118.782, -0.000, 0.000, 0.010, 10.426, -12.000},
{10.925, 49.888, 118.782, -0.000, 0.000, 0.010, 10.925, -12.000},
{11.436, 51.076, 118.782, 0.000, 0.000, 0.010, 11.436, -12.000},
{11.958, 52.264, 118.782, -0.000, 0.000, 0.010, 11.958, -12.000},
{12.493, 53.452, 118.782, 0.000, 0.000, 0.010, 12.493, -12.000},
{13.039, 54.640, 118.782, 0.000, 0.000, 0.010, 13.039, -12.000},
{13.598, 55.827, 118.782, -0.000, 0.000, 0.010, 13.598, -12.000},
{14.167, 56.986, 115.812, -296.955, 0.000, 0.010, 14.167, -12.000},
{14.748, 58.084, 109.873, -593.909, 0.000, 0.010, 14.748, -12.000},
{15.335, 58.695, 61.046, -4882.734, 6.283, 0.010, 15.335, -12.000},
{15.908, 57.329, -136.617, -19766.250, 6.281, 0.010, 15.908, -12.001},
{16.466, 55.749, -157.949, -2133.232, 6.276, 0.010, 16.466, -12.003},
{17.008, 54.208, -154.163, 378.601, 6.270, 0.010, 17.008, -12.009},
{17.535, 52.714, -149.355, 480.809, 6.261, 0.010, 17.535, -12.018},
{18.048, 51.280, -143.352, 600.321, 6.251, 0.010, 18.048, -12.032},
{18.547, 49.921, -135.968, 738.363, 6.239, 0.010, 18.547, -12.051},
{19.034, 48.650, -127.030, 893.794, 6.226, 0.010, 19.032, -12.075},
{19.509, 47.486, -116.400, 1063.020, 6.211, 0.010, 19.506, -12.106},
{19.973, 46.446, -104.000, 1240.029, 6.195, 0.010, 19.969, -12.143},
{20.429, 45.548, -89.833, 1416.622, 6.178, 0.010, 20.423, -12.187},
{20.877, 44.808, -74.004, 1582.897, 6.160, 0.010, 20.868, -12.238},
{21.319, 44.241, -56.724, 1727.997, 6.141, 0.010, 21.306, -12.296},
{21.758, 43.858, -38.314, 1841.087, 6.121, 0.010, 21.740, -12.363},
{22.194, 43.666, -19.189, 1912.471, 6.101, 0.010, 22.170, -12.437},
{22.631, 43.667, 0.158, 1934.670, 6.081, 0.010, 22.599, -12.521},
{23.070, 43.859, 19.191, 1903.317, 6.062, 0.010, 23.028, -12.613},
{23.512, 44.222, 36.239, 1704.800, 6.042, 0.010, 23.458, -12.714},
{23.959, 44.740, 51.851, 1561.147, 6.023, 0.010, 23.891, -12.825},
{24.413, 45.407, 66.696, 1484.536, 6.005, 0.010, 24.329, -12.946},
{24.875, 46.200, 79.312, 1261.573, 5.987, 0.010, 24.772, -13.077},
{25.346, 47.095, 89.449, 1013.729, 5.970, 0.010, 25.221, -13.218},
{25.827, 48.064, 96.966, 751.705, 5.955, 0.010, 25.678, -13.370},
{26.318, 49.083, 101.822, 485.561, 5.940, 0.010, 26.141, -13.532},
{26.819, 50.123, 104.062, 223.997, 5.927, 0.010, 26.612, -13.703},
{27.330, 51.161, 103.801, -26.078, 5.915, 0.010, 27.090, -13.885},
{27.852, 52.173, 101.204, -259.694, 5.904, 0.010, 27.576, -14.075},
{28.384, 53.138, 96.467, -473.730, 5.895, 0.010, 28.069, -14.274},
{28.924, 54.036, 89.800, -666.673, 5.887, 0.010, 28.568, -14.480},
{29.472, 54.850, 81.417, -838.275, 5.880, 0.010, 29.073, -14.694},
{30.028, 55.565, 71.525, -989.191, 5.875, 0.010, 29.584, -14.913},
{30.590, 56.169, 60.319, -1120.635, 5.870, 0.010, 30.099, -15.137},
{31.156, 56.648, 47.978, -1234.082, 5.867, 0.010, 30.617, -15.366},
{31.726, 56.995, 34.668, -1331.038, 5.865, 0.010, 31.138, -15.597},
{32.298, 57.200, 20.539, -1412.876, 5.864, 0.010, 31.661, -15.829},
{32.871, 57.258, 5.731, -1480.734, 5.864, 0.010, 32.184, -16.062},
{33.442, 57.162, -9.623, -1535.474, 5.864, 0.010, 32.706, -16.295},
{34.012, 56.925, -23.612, -1398.865, 5.866, 0.010, 33.226, -16.526},
{34.577, 56.579, -34.655, -1104.342, 5.868, 0.010, 33.744, -16.755},
{35.139, 56.136, -44.276, -962.070, 5.871, 0.010, 34.258, -16.980},
{35.695, 55.599, -53.683, -940.675, 5.874, 0.010, 34.768, -17.202},
{36.245, 54.971, -62.829, -914.672, 5.878, 0.010, 35.272, -17.420},
{36.787, 54.254, -71.673, -884.354, 5.882, 0.010, 35.772, -17.633},
{37.322, 53.453, -80.173, -849.970, 5.887, 0.010, 36.264, -17.840},
{37.847, 52.570, -88.290, -811.761, 5.892, 0.010, 36.750, -18.042},
{38.363, 51.610, -95.990, -769.996, 5.897, 0.010, 37.227, -18.238},
{38.869, 50.577, -103.240, -724.988, 5.902, 0.010, 37.696, -18.427},
{39.364, 49.477, -110.011, -677.107, 5.907, 0.010, 38.156, -18.610},
{39.847, 48.314, -116.279, -626.780, 5.912, 0.010, 38.606, -18.787},
{40.318, 47.094, -122.024, -574.483, 5.917, 0.010, 39.045, -18.956},
{40.776, 45.822, -127.231, -520.735, 5.922, 0.010, 39.473, -19.119},
{41.221, 44.503, -131.892, -466.081, 5.927, 0.010, 39.890, -19.275},
{41.653, 43.143, -136.003, -411.077, 5.932, 0.010, 40.295, -19.424},
{42.070, 41.747, -139.566, -356.276, 5.937, 0.010, 40.687, -19.567},
{42.473, 40.321, -142.588, -302.214, 5.941, 0.010, 41.067, -19.703},
{42.862, 38.871, -145.082, -249.398, 5.946, 0.010, 41.433, -19.833},
{43.236, 37.400, -147.065, -198.293, 5.950, 0.010, 41.786, -19.956},
{43.595, 35.914, -148.558, -149.320, 5.953, 0.010, 42.126, -20.073},
{43.939, 34.418, -149.586, -102.846, 5.957, 0.010, 42.452, -20.183},
{44.269, 32.917, -150.178, -59.189, 5.960, 0.010, 42.764, -20.288},
{44.583, 31.413, -150.364, -18.610, 5.963, 0.010, 43.062, -20.388},
{44.882, 29.911, -150.177, 18.682, 5.966, 0.010, 43.346, -20.481},
{45.166, 28.415, -149.652, 52.525, 5.968, 0.010, 43.616, -20.570},
{45.435, 26.926, -148.824, 82.804, 5.971, 0.010, 43.872, -20.653},
{45.690, 25.449, -147.730, 109.446, 5.973, 0.010, 44.114, -20.731},
{45.930, 23.985, -146.406, 132.417, 5.974, 0.010, 44.343, -20.804},
{46.155, 22.536, -144.888, 151.717, 5.976, 0.010, 44.557, -20.872},
{46.366, 21.104, -143.215, 167.376, 5.977, 0.010, 44.759, -20.936},
{46.563, 19.690, -141.420, 179.453, 5.978, 0.010, 44.946, -20.995},
{46.746, 18.295, -139.540, 188.031, 5.979, 0.010, 45.121, -21.050},
{46.915, 16.918, -137.608, 193.218, 5.980, 0.010, 45.282, -21.100},
{47.071, 15.562, -135.656, 195.141, 5.981, 0.010, 45.431, -21.147},
{47.213, 14.225, -133.717, 193.946, 5.981, 0.010, 45.567, -21.189},
{47.342, 12.907, -131.819, 189.797, 5.982, 0.010, 45.690, -21.227},
{47.458, 11.624, -128.213, 360.620, 5.982, 0.010, 45.801, -21.262},
{47.562, 10.408, -121.677, 653.537, 5.982, 0.010, 45.900, -21.293},
{47.655, 9.267, -114.055, 762.175, 5.983, 0.010, 45.989, -21.320},
{47.737, 8.201, -106.649, 740.640, 5.983, 0.010, 46.067, -21.344},
{47.809, 7.206, -99.448, 720.125, 5.983, 0.010, 46.136, -21.366},
{47.872, 6.282, -92.439, 700.914, 5.983, 0.010, 46.196, -21.384},
{47.926, 5.426, -85.606, 683.220, 5.983, 0.010, 46.248, -21.400},
{47.972, 4.636, -78.935, 667.187, 5.983, 0.010, 46.292, -21.414},
{48.012, 3.912, -72.406, 652.898, 5.983, 0.010, 46.330, -21.426},
{48.044, 3.252, -66.002, 640.384, 5.983, 0.010, 46.361, -21.435},
{48.071, 2.655, -59.705, 629.628, 5.983, 0.010, 46.386, -21.443},
{48.092, 2.120, -53.500, 620.574, 5.983, 0.010, 46.406, -21.449},
{48.108, 1.646, -47.368, 613.133, 5.983, 0.010, 46.422, -21.454},
{48.121, 1.234, -41.297, 607.186, 5.983, 0.010, 46.434, -21.458},
{48.129, 0.881, -35.271, 602.594, 5.983, 0.010, 46.442, -21.460},
{48.135, 0.588, -29.279, 599.198, 5.983, 0.010, 46.448, -21.462},
{48.139, 0.355, -23.310, 596.829, 5.983, 0.010, 46.451, -21.463},
{48.141, 0.181, -17.357, 595.306, 5.983, 0.010, 46.453, -21.464},
{48.141, 0.067, -11.413, 594.442, 5.983, 0.010, 46.454, -21.464},
{48.141, 0.013, -5.472, 594.046, 5.983, 0.010, 46.454, -21.464},
{48.141, 0.000, -1.251, 422.105, 5.983, 0.010, 46.454, -21.464}};
#endif