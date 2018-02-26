#ifndef FromRightFirstCube_ToLeftSwitchPath_H
#define FromRightFirstCube_ToLeftSwitchPath_H
int num_index = 220;
double left_wheel[220][8] ={ 
{0.000, 0.060, 5.968, 596.784, 1.571, 0.010, 197.550, 25.001},
{0.001, 0.119, 5.968, -0.000, 1.571, 0.010, 197.550, 25.003},
{0.004, 0.269, 14.920, 895.176, 1.571, 0.010, 197.550, 25.005},
{0.009, 0.477, 20.887, 596.784, 1.571, 0.010, 197.550, 25.010},
{0.016, 0.746, 26.855, 596.783, 1.571, 0.010, 197.550, 25.018},
{0.027, 1.074, 32.823, 596.783, 1.571, 0.010, 197.550, 25.028},
{0.042, 1.462, 38.791, 596.782, 1.571, 0.010, 197.550, 25.043},
{0.061, 1.910, 44.759, 596.781, 1.571, 0.010, 197.550, 25.062},
{0.085, 2.417, 50.727, 596.780, 1.571, 0.010, 197.550, 25.086},
{0.115, 2.984, 56.694, 596.778, 1.571, 0.010, 197.550, 25.116},
{0.151, 3.611, 62.662, 596.775, 1.571, 0.010, 197.550, 25.152},
{0.194, 4.297, 68.630, 596.773, 1.571, 0.010, 197.550, 25.195},
{0.244, 5.043, 74.597, 596.769, 1.571, 0.010, 197.550, 25.246},
{0.303, 5.848, 80.565, 596.765, 1.571, 0.010, 197.550, 25.304},
{0.370, 6.714, 86.533, 596.761, 1.571, 0.010, 197.550, 25.371},
{0.446, 7.639, 92.500, 596.756, 1.571, 0.010, 197.550, 25.448},
{0.533, 8.623, 98.468, 596.750, 1.571, 0.010, 197.550, 25.534},
{0.629, 9.668, 104.435, 596.744, 1.571, 0.010, 197.550, 25.631},
{0.737, 10.772, 110.403, 596.737, 1.571, 0.010, 197.550, 25.738},
{0.856, 11.936, 116.370, 596.729, 1.571, 0.010, 197.550, 25.858},
{0.988, 13.129, 119.353, 298.333, 1.571, 0.010, 197.550, 25.989},
{1.131, 14.323, 119.353, -0.061, 1.571, 0.010, 197.550, 26.132},
{1.286, 15.516, 119.352, -0.065, 1.571, 0.010, 197.550, 26.287},
{1.453, 16.710, 119.351, -0.069, 1.571, 0.010, 197.550, 26.454},
{1.632, 17.903, 119.351, -0.072, 1.571, 0.010, 197.550, 26.633},
{1.823, 19.097, 119.350, -0.075, 1.571, 0.010, 197.550, 26.824},
{2.026, 20.290, 119.349, -0.078, 1.571, 0.010, 197.550, 27.027},
{2.241, 21.484, 119.348, -0.080, 1.571, 0.010, 197.550, 27.242},
{2.468, 22.677, 119.347, -0.081, 1.571, 0.010, 197.550, 27.469},
{2.706, 23.871, 119.347, -0.082, 1.571, 0.010, 197.550, 27.708},
{2.957, 25.064, 119.346, -0.083, 1.571, 0.010, 197.550, 27.958},
{3.220, 26.257, 119.345, -0.083, 1.571, 0.010, 197.550, 28.221},
{3.494, 27.451, 119.344, -0.082, 1.571, 0.010, 197.550, 28.495},
{3.781, 28.644, 119.343, -0.081, 1.571, 0.010, 197.550, 28.782},
{4.079, 29.838, 119.343, -0.080, 1.571, 0.010, 197.550, 29.080},
{4.389, 31.031, 119.342, -0.077, 1.571, 0.010, 197.550, 29.390},
{4.711, 32.225, 119.341, -0.074, 1.571, 0.010, 197.550, 29.713},
{5.046, 33.418, 119.340, -0.071, 1.571, 0.010, 197.550, 30.047},
{5.392, 34.611, 119.340, -0.067, 1.571, 0.010, 197.550, 30.393},
{5.750, 35.805, 119.339, -0.062, 1.571, 0.010, 197.551, 30.751},
{6.120, 36.998, 119.338, -0.057, 1.571, 0.010, 197.551, 31.121},
{6.502, 38.192, 119.338, -0.051, 1.571, 0.010, 197.551, 31.503},
{6.896, 39.385, 119.337, -0.044, 1.571, 0.010, 197.551, 31.897},
{7.301, 40.578, 119.337, -0.037, 1.571, 0.010, 197.551, 32.303},
{7.719, 41.772, 119.337, -0.030, 1.571, 0.010, 197.551, 32.720},
{8.149, 42.965, 119.337, -0.021, 1.571, 0.010, 197.551, 33.150},
{8.590, 44.158, 119.336, -0.012, 1.571, 0.010, 197.551, 33.591},
{9.044, 45.352, 119.336, -0.003, 1.571, 0.010, 197.551, 34.045},
{9.509, 46.545, 119.336, 0.007, 1.571, 0.010, 197.551, 34.510},
{9.987, 47.738, 119.337, 0.017, 1.571, 0.010, 197.551, 34.988},
{10.476, 48.932, 119.337, 0.028, 1.571, 0.010, 197.551, 35.477},
{10.977, 50.125, 119.337, 0.040, 1.571, 0.010, 197.551, 35.978},
{11.490, 51.319, 119.338, 0.052, 1.571, 0.010, 197.551, 36.492},
{12.016, 52.512, 119.339, 0.064, 1.571, 0.010, 197.551, 37.017},
{12.553, 53.705, 119.339, 0.076, 1.571, 0.010, 197.551, 37.554},
{13.102, 54.899, 119.340, 0.089, 1.571, 0.010, 197.551, 38.103},
{13.662, 56.092, 119.341, 0.103, 1.571, 0.010, 197.551, 38.664},
{14.235, 57.286, 119.342, 0.116, 1.571, 0.010, 197.551, 39.237},
{14.820, 58.479, 119.344, 0.130, 1.571, 0.010, 197.551, 39.821},
{15.417, 59.673, 119.345, 0.143, 1.571, 0.010, 197.551, 40.418},
{16.026, 60.866, 119.347, 0.157, 1.571, 0.010, 197.551, 41.027},
{16.646, 62.059, 119.348, 0.171, 1.571, 0.010, 197.551, 41.647},
{17.279, 63.253, 119.350, 0.184, 1.571, 0.010, 197.551, 42.280},
{17.923, 64.446, 119.352, 0.198, 1.571, 0.010, 197.551, 42.924},
{18.580, 65.640, 119.354, 0.211, 1.571, 0.010, 197.551, 43.581},
{19.248, 66.834, 119.357, 0.224, 1.571, 0.010, 197.551, 44.249},
{19.928, 68.027, 119.359, 0.237, 1.571, 0.010, 197.551, 44.929},
{20.620, 69.221, 119.361, 0.249, 1.571, 0.010, 197.551, 45.622},
{21.324, 70.414, 119.364, 0.261, 1.571, 0.010, 197.551, 46.326},
{22.041, 71.608, 119.367, 0.272, 1.571, 0.010, 197.551, 47.042},
{22.769, 72.802, 119.370, 0.282, 1.571, 0.010, 197.551, 47.770},
{23.509, 73.996, 119.372, 0.292, 1.571, 0.010, 197.551, 48.510},
{24.260, 75.189, 119.375, 0.300, 1.571, 0.010, 197.551, 49.262},
{25.024, 76.383, 119.379, 0.308, 1.571, 0.010, 197.551, 50.025},
{25.800, 77.577, 119.382, 0.314, 1.571, 0.010, 197.551, 50.801},
{26.588, 78.771, 119.385, 0.319, 1.571, 0.010, 197.551, 51.589},
{27.387, 79.965, 119.388, 0.322, 1.571, 0.010, 197.551, 52.389},
{28.199, 81.159, 119.391, 0.324, 1.571, 0.010, 197.551, 53.200},
{29.022, 82.352, 119.395, 0.325, 1.571, 0.010, 197.550, 54.024},
{29.858, 83.546, 119.398, 0.323, 1.571, 0.010, 197.550, 54.859},
{30.705, 84.740, 119.401, 0.319, 1.571, 0.010, 197.550, 55.707},
{31.565, 85.934, 119.404, 0.314, 1.571, 0.010, 197.550, 56.566},
{32.436, 87.129, 119.407, 0.306, 1.571, 0.010, 197.550, 57.437},
{33.319, 88.323, 119.410, 0.295, 1.571, 0.010, 197.550, 58.320},
{34.214, 89.517, 119.413, 0.282, 1.571, 0.010, 197.550, 59.216},
{35.121, 90.711, 119.416, 0.266, 1.571, 0.010, 197.550, 60.123},
{36.041, 91.905, 119.418, 0.247, 1.571, 0.010, 197.550, 61.042},
{36.972, 93.099, 119.420, 0.225, 1.571, 0.010, 197.550, 61.973},
{37.914, 94.294, 119.422, 0.199, 1.571, 0.010, 197.550, 62.916},
{38.869, 95.488, 119.424, 0.170, 1.571, 0.010, 197.550, 63.871},
{39.836, 96.652, 116.441, -298.265, 1.571, 0.010, 197.550, 64.837},
{40.813, 97.757, 110.474, -596.714, 1.571, 0.010, 197.550, 65.815},
{41.801, 98.802, 104.507, -596.771, 1.571, 0.010, 197.549, 66.803},
{42.799, 99.787, 98.538, -596.831, 1.571, 0.010, 197.549, 67.801},
{43.806, 100.713, 92.569, -596.893, 1.571, 0.010, 197.549, 68.808},
{44.822, 101.579, 86.600, -596.959, 1.571, 0.010, 197.549, 69.823},
{45.846, 102.385, 80.629, -597.026, 1.571, 0.010, 197.549, 70.847},
{46.877, 103.132, 74.659, -597.095, 1.571, 0.010, 197.549, 71.879},
{47.916, 103.819, 68.687, -597.166, 1.571, 0.010, 197.549, 72.917},
{48.960, 104.446, 62.714, -597.237, 1.571, 0.010, 197.549, 73.961},
{50.010, 105.013, 56.741, -597.308, 1.571, 0.010, 197.549, 75.011},
{51.065, 105.521, 50.768, -597.379, 1.571, 0.010, 197.549, 76.067},
{52.125, 105.969, 44.793, -597.450, 1.571, 0.010, 197.549, 77.126},
{53.189, 106.357, 38.818, -597.518, 1.571, 0.010, 197.549, 78.190},
{54.256, 106.686, 32.842, -597.585, 1.571, 0.010, 197.549, 79.257},
{55.325, 106.954, 26.866, -597.650, 1.571, 0.010, 197.549, 80.326},
{56.397, 107.163, 20.888, -597.711, 1.571, 0.010, 197.549, 81.398},
{57.470, 107.312, 14.911, -597.768, 1.571, 0.010, 197.549, 82.471},
{58.544, 107.402, 8.933, -597.821, 1.571, 0.010, 197.549, 83.545},
{59.618, 107.417, 1.514, -741.827, 1.571, 0.010, 197.549, 84.619},
{60.692, 107.358, -5.904, -741.867, 1.571, 0.010, 197.549, 85.693},
{61.764, 107.239, -11.884, -597.944, 1.571, 0.010, 197.549, 86.765},
{62.835, 107.060, -17.864, -597.973, 1.571, 0.010, 197.549, 87.836},
{63.903, 106.822, -23.843, -597.994, 1.571, 0.010, 197.549, 88.904},
{64.968, 106.524, -29.824, -598.008, 1.571, 0.010, 197.550, 89.969},
{66.030, 106.165, -35.804, -598.014, 1.571, 0.010, 197.550, 91.031},
{67.087, 105.748, -41.784, -598.012, 1.571, 0.010, 197.550, 92.088},
{68.140, 105.270, -47.764, -598.001, 1.571, 0.010, 197.550, 93.141},
{69.187, 104.733, -53.744, -597.982, 1.571, 0.010, 197.550, 94.188},
{70.228, 104.125, -60.729, -698.526, 1.571, 0.010, 197.550, 95.230},
{71.260, 103.119, -100.586, -3985.695, 1.571, 0.010, 197.550, 96.261},
{72.277, 101.721, -139.813, -3922.750, 1.572, 0.010, 197.549, 97.278},
{73.277, 100.054, -166.697, -2688.363, 1.573, 0.010, 197.548, 98.279},
{74.259, 98.138, -191.662, -2496.487, 1.576, 0.010, 197.544, 99.260},
{75.219, 95.987, -215.092, -2343.019, 1.579, 0.010, 197.538, 100.220},
{76.155, 93.613, -237.381, -2228.846, 1.584, 0.010, 197.528, 101.156},
{77.065, 91.024, -258.910, -2152.911, 1.590, 0.010, 197.513, 102.066},
{77.947, 88.224, -280.037, -2112.785, 1.597, 0.010, 197.494, 102.948},
{78.799, 85.213, -301.087, -2104.994, 1.606, 0.010, 197.468, 103.800},
{79.619, 82.002, -321.113, -2002.535, 1.616, 0.010, 197.435, 104.619},
{80.405, 78.609, -339.255, -1814.176, 1.628, 0.010, 197.395, 105.404},
{81.156, 75.036, -357.291, -1803.617, 1.642, 0.010, 197.347, 106.153},
{81.869, 71.267, -376.857, -1956.676, 1.658, 0.010, 197.291, 106.863},
{82.541, 67.286, -398.129, -2127.112, 1.677, 0.010, 197.226, 107.533},
{83.172, 63.075, -421.169, -2304.066, 1.697, 0.010, 197.153, 108.160},
{83.758, 58.616, -445.887, -2471.745, 1.721, 0.010, 197.072, 108.740},
{84.297, 53.896, -471.960, -2607.311, 1.747, 0.010, 196.985, 109.272},
{84.786, 48.909, -498.744, -2678.432, 1.776, 0.010, 196.892, 109.752},
{85.223, 43.657, -525.153, -2640.919, 1.809, 0.010, 196.797, 110.178},
{85.605, 38.162, -549.526, -2437.228, 1.845, 0.010, 196.700, 110.548},
{85.929, 32.467, -569.500, -1997.452, 1.884, 0.010, 196.607, 110.858},
{86.196, 26.647, -581.951, -1245.099, 1.928, 0.010, 196.519, 111.110},
{86.404, 20.817, -583.057, -110.632, 1.975, 0.010, 196.442, 111.304},
{86.555, 15.131, -568.606, 1445.106, 2.025, 0.010, 196.379, 111.441},
{86.653, 9.784, -534.619, 3398.728, 2.079, 0.010, 196.334, 111.528},
{86.703, 5.001, -478.305, 5631.421, 2.136, 0.010, 196.309, 111.571},
{86.713, 1.010, -399.180, 7912.536, 2.195, 0.010, 196.303, 111.580},
{86.733, 1.991, 98.129, 49730.900, 2.256, 0.010, 196.316, 111.564},
{86.772, 3.862, 187.111, 8898.110, 2.317, 0.010, 196.341, 111.535},
{86.817, 4.556, 69.414, -11769.628, 2.378, 0.010, 196.373, 111.502},
{86.858, 4.126, -43.045, -11245.914, 2.437, 0.010, 196.404, 111.475},
{86.886, 2.712, -141.325, -9828.029, 2.495, 0.010, 196.425, 111.458},
{86.891, 0.520, -219.247, -7792.182, 2.549, 0.010, 196.429, 111.454},
{86.913, 2.222, 170.193, 38944.027, 2.601, 0.010, 196.410, 111.466},
{86.966, 5.289, 306.658, 13646.480, 2.649, 0.010, 196.364, 111.492},
{87.051, 8.484, 319.560, 1290.225, 2.693, 0.010, 196.288, 111.531},
{87.167, 11.653, 316.903, -265.720, 2.734, 0.010, 196.182, 111.579},
{87.314, 14.682, 302.922, -1398.098, 2.772, 0.010, 196.046, 111.634},
{87.489, 17.497, 281.448, -2147.427, 2.806, 0.010, 195.882, 111.695},
{87.690, 20.053, 255.610, -2583.765, 2.837, 0.010, 195.692, 111.758},
{87.913, 22.331, 227.775, -2783.504, 2.866, 0.010, 195.478, 111.821},
{88.156, 24.327, 199.615, -2816.021, 2.892, 0.010, 195.243, 111.884},
{88.417, 26.049, 172.235, -2737.993, 2.916, 0.010, 194.989, 111.946},
{88.692, 27.512, 146.310, -2592.508, 2.937, 0.010, 194.721, 112.004},
{88.979, 28.734, 122.205, -2410.533, 2.957, 0.010, 194.439, 112.060},
{89.276, 29.735, 100.072, -2213.286, 2.975, 0.010, 194.146, 112.112},
{89.582, 30.534, 79.925, -2014.635, 2.991, 0.010, 193.844, 112.160},
{89.893, 31.151, 61.694, -1823.135, 3.006, 0.010, 193.536, 112.204},
{90.209, 31.604, 45.257, -1643.678, 3.019, 0.010, 193.223, 112.245},
{90.528, 31.909, 30.470, -1478.690, 3.031, 0.010, 192.906, 112.282},
{90.849, 32.080, 17.180, -1329.011, 3.043, 0.010, 192.587, 112.315},
{91.171, 32.133, 5.236, -1194.477, 3.053, 0.010, 192.267, 112.346},
{91.491, 32.078, -5.508, -1074.361, 3.062, 0.010, 191.947, 112.373},
{91.811, 31.926, -15.184, -967.611, 3.070, 0.010, 191.629, 112.397},
{92.127, 31.687, -23.915, -873.049, 3.078, 0.010, 191.313, 112.418},
{92.441, 31.369, -31.809, -789.454, 3.085, 0.010, 190.999, 112.437},
{92.751, 30.979, -38.966, -715.660, 3.091, 0.010, 190.690, 112.453},
{93.056, 30.524, -45.471, -650.553, 3.097, 0.010, 190.385, 112.468},
{93.356, 30.010, -51.403, -593.120, 3.102, 0.010, 190.085, 112.480},
{93.651, 29.442, -56.827, -542.439, 3.107, 0.010, 189.791, 112.491},
{93.939, 28.824, -61.804, -497.679, 3.111, 0.010, 189.503, 112.501},
{94.221, 28.160, -66.385, -458.097, 3.115, 0.010, 189.222, 112.509},
{94.495, 27.454, -70.615, -423.041, 3.118, 0.010, 188.947, 112.516},
{94.762, 26.709, -74.534, -391.915, 3.121, 0.010, 188.680, 112.521},
{95.021, 25.927, -78.176, -364.203, 3.124, 0.010, 188.421, 112.526},
{95.273, 25.111, -81.571, -339.437, 3.126, 0.010, 188.170, 112.531},
{95.515, 24.264, -84.743, -317.209, 3.128, 0.010, 187.927, 112.534},
{95.749, 23.386, -87.714, -297.147, 3.130, 0.010, 187.693, 112.537},
{95.974, 22.481, -90.503, -278.922, 3.132, 0.010, 187.469, 112.539},
{96.189, 21.550, -93.126, -262.243, 3.133, 0.010, 187.253, 112.541},
{96.395, 20.594, -95.594, -246.844, 3.134, 0.010, 187.047, 112.543},
{96.591, 19.615, -97.919, -232.489, 3.135, 0.010, 186.851, 112.544},
{96.778, 18.614, -100.109, -218.970, 3.136, 0.010, 186.665, 112.545},
{96.953, 17.592, -102.170, -206.097, 3.137, 0.010, 186.489, 112.546},
{97.119, 16.551, -104.107, -193.708, 3.138, 0.010, 186.323, 112.547},
{97.274, 15.492, -105.923, -181.651, 3.138, 0.010, 186.169, 112.547},
{97.418, 14.416, -107.621, -169.805, 3.139, 0.010, 186.024, 112.548},
{97.551, 13.324, -109.202, -158.057, 3.139, 0.010, 185.891, 112.548},
{97.673, 12.217, -110.665, -146.316, 3.139, 0.010, 185.769, 112.549},
{97.785, 11.111, -110.602, 6.353, 3.139, 0.010, 185.658, 112.549},
{97.885, 10.036, -107.471, 313.034, 3.140, 0.010, 185.557, 112.549},
{97.975, 9.010, -102.653, 481.862, 3.140, 0.010, 185.467, 112.549},
{98.055, 8.033, -97.664, 498.897, 3.140, 0.010, 185.387, 112.549},
{98.126, 7.108, -92.521, 514.232, 3.140, 0.010, 185.316, 112.549},
{98.189, 6.236, -87.242, 527.944, 3.140, 0.010, 185.254, 112.550},
{98.243, 5.417, -81.841, 540.107, 3.140, 0.010, 185.199, 112.550},
{98.290, 4.654, -76.333, 550.796, 3.140, 0.010, 185.153, 112.550},
{98.329, 3.946, -70.732, 560.089, 3.140, 0.010, 185.113, 112.550},
{98.362, 3.296, -65.051, 568.069, 3.140, 0.010, 185.080, 112.550},
{98.389, 2.703, -59.303, 574.820, 3.140, 0.010, 185.053, 112.550},
{98.411, 2.168, -53.499, 580.436, 3.140, 0.010, 185.032, 112.550},
{98.428, 1.691, -47.649, 585.012, 3.140, 0.010, 185.015, 112.550},
{98.440, 1.274, -41.762, 588.647, 3.140, 0.010, 185.002, 112.550},
{98.449, 0.915, -35.848, 591.445, 3.140, 0.010, 184.993, 112.550},
{98.456, 0.616, -29.913, 593.514, 3.140, 0.010, 184.987, 112.550},
{98.459, 0.377, -23.963, 594.961, 3.140, 0.010, 184.983, 112.550},
{98.461, 0.197, -18.004, 595.898, 3.140, 0.010, 184.981, 112.550},
{98.462, 0.076, -12.040, 596.437, 3.140, 0.010, 184.980, 112.550},
{98.462, 0.015, -6.073, 596.691, 3.140, 0.010, 184.980, 112.550},
{98.462, 0.000, -1.544, 452.828, 3.140, 0.010, 184.980, 112.550}};
double right_wheel[220][8] ={ 
{0.000, 0.060, 5.968, 596.784, 1.571, 0.010, 222.450, 24.999},
{0.001, 0.119, 5.968, 0.000, 1.571, 0.010, 222.450, 25.000},
{0.004, 0.269, 14.920, 895.176, 1.571, 0.010, 222.450, 25.003},
{0.009, 0.477, 20.887, 596.784, 1.571, 0.010, 222.450, 25.008},
{0.016, 0.746, 26.855, 596.785, 1.571, 0.010, 222.450, 25.015},
{0.027, 1.074, 32.823, 596.785, 1.571, 0.010, 222.450, 25.026},
{0.042, 1.462, 38.791, 596.786, 1.571, 0.010, 222.450, 25.041},
{0.061, 1.910, 44.759, 596.787, 1.571, 0.010, 222.450, 25.060},
{0.085, 2.417, 50.727, 596.788, 1.571, 0.010, 222.450, 25.084},
{0.115, 2.984, 56.695, 596.790, 1.571, 0.010, 222.450, 25.114},
{0.151, 3.611, 62.663, 596.793, 1.571, 0.010, 222.450, 25.150},
{0.194, 4.297, 68.631, 596.795, 1.571, 0.010, 222.450, 25.193},
{0.244, 5.043, 74.599, 596.799, 1.571, 0.010, 222.450, 25.243},
{0.303, 5.849, 80.567, 596.803, 1.571, 0.010, 222.450, 25.302},
{0.370, 6.714, 86.535, 596.807, 1.571, 0.010, 222.450, 25.369},
{0.446, 7.639, 92.503, 596.812, 1.571, 0.010, 222.450, 25.445},
{0.533, 8.624, 98.471, 596.818, 1.571, 0.010, 222.450, 25.531},
{0.629, 9.668, 104.439, 596.824, 1.571, 0.010, 222.450, 25.628},
{0.737, 10.772, 110.407, 596.831, 1.571, 0.010, 222.450, 25.736},
{0.856, 11.936, 116.376, 596.839, 1.571, 0.010, 222.450, 25.855},
{0.988, 13.129, 119.360, 298.451, 1.571, 0.010, 222.450, 25.986},
{1.131, 14.323, 119.361, 0.061, 1.571, 0.010, 222.450, 26.130},
{1.286, 15.517, 119.362, 0.065, 1.571, 0.010, 222.450, 26.285},
{1.453, 16.710, 119.362, 0.069, 1.571, 0.010, 222.450, 26.452},
{1.632, 17.904, 119.363, 0.072, 1.571, 0.010, 222.450, 26.631},
{1.823, 19.098, 119.364, 0.075, 1.571, 0.010, 222.450, 26.822},
{2.026, 20.291, 119.365, 0.078, 1.571, 0.010, 222.450, 27.025},
{2.241, 21.485, 119.365, 0.080, 1.571, 0.010, 222.450, 27.240},
{2.468, 22.678, 119.366, 0.081, 1.571, 0.010, 222.450, 27.467},
{2.706, 23.872, 119.367, 0.082, 1.571, 0.010, 222.450, 27.705},
{2.957, 25.066, 119.368, 0.083, 1.571, 0.010, 222.450, 27.956},
{3.220, 26.260, 119.369, 0.083, 1.571, 0.010, 222.450, 28.219},
{3.494, 27.453, 119.369, 0.082, 1.571, 0.010, 222.450, 28.493},
{3.781, 28.647, 119.370, 0.081, 1.571, 0.010, 222.450, 28.780},
{4.079, 29.841, 119.371, 0.080, 1.571, 0.010, 222.450, 29.078},
{4.389, 31.034, 119.372, 0.077, 1.571, 0.010, 222.450, 29.388},
{4.712, 32.228, 119.373, 0.074, 1.571, 0.010, 222.450, 29.711},
{5.046, 33.422, 119.373, 0.071, 1.571, 0.010, 222.450, 30.045},
{5.392, 34.616, 119.374, 0.067, 1.571, 0.010, 222.450, 30.391},
{5.750, 35.809, 119.375, 0.062, 1.571, 0.010, 222.451, 30.749},
{6.120, 37.003, 119.375, 0.057, 1.571, 0.010, 222.451, 31.119},
{6.502, 38.197, 119.376, 0.051, 1.571, 0.010, 222.451, 31.501},
{6.896, 39.391, 119.376, 0.044, 1.571, 0.010, 222.451, 31.895},
{7.302, 40.584, 119.377, 0.037, 1.571, 0.010, 222.451, 32.301},
{7.720, 41.778, 119.377, 0.030, 1.571, 0.010, 222.451, 32.719},
{8.149, 42.972, 119.377, 0.021, 1.571, 0.010, 222.451, 33.148},
{8.591, 44.166, 119.377, 0.012, 1.571, 0.010, 222.451, 33.590},
{9.045, 45.359, 119.377, 0.003, 1.571, 0.010, 222.451, 34.044},
{9.510, 46.553, 119.377, -0.007, 1.571, 0.010, 222.451, 34.509},
{9.988, 47.747, 119.377, -0.017, 1.571, 0.010, 222.451, 34.987},
{10.477, 48.941, 119.377, -0.028, 1.571, 0.010, 222.451, 35.476},
{10.978, 50.134, 119.376, -0.040, 1.571, 0.010, 222.451, 35.977},
{11.492, 51.328, 119.376, -0.052, 1.571, 0.010, 222.451, 36.491},
{12.017, 52.522, 119.375, -0.064, 1.571, 0.010, 222.451, 37.016},
{12.554, 53.716, 119.374, -0.076, 1.571, 0.010, 222.451, 37.553},
{13.103, 54.909, 119.373, -0.089, 1.571, 0.010, 222.451, 38.102},
{13.664, 56.103, 119.372, -0.103, 1.571, 0.010, 222.451, 38.663},
{14.237, 57.297, 119.371, -0.116, 1.571, 0.010, 222.451, 39.236},
{14.822, 58.491, 119.370, -0.130, 1.571, 0.010, 222.451, 39.821},
{15.419, 59.684, 119.369, -0.143, 1.571, 0.010, 222.451, 40.418},
{16.028, 60.878, 119.367, -0.157, 1.571, 0.010, 222.451, 41.027},
{16.648, 62.072, 119.365, -0.171, 1.571, 0.010, 222.451, 41.647},
{17.281, 63.265, 119.363, -0.184, 1.571, 0.010, 222.451, 42.280},
{17.926, 64.459, 119.361, -0.198, 1.571, 0.010, 222.451, 42.925},
{18.582, 65.652, 119.359, -0.211, 1.571, 0.010, 222.451, 43.581},
{19.251, 66.846, 119.357, -0.224, 1.571, 0.010, 222.451, 44.249},
{19.931, 68.040, 119.355, -0.237, 1.571, 0.010, 222.451, 44.930},
{20.623, 69.233, 119.352, -0.249, 1.571, 0.010, 222.451, 45.622},
{21.328, 70.427, 119.350, -0.261, 1.571, 0.010, 222.451, 46.326},
{22.044, 71.620, 119.347, -0.272, 1.571, 0.010, 222.451, 47.043},
{22.772, 72.814, 119.344, -0.282, 1.571, 0.010, 222.451, 47.771},
{23.512, 74.007, 119.341, -0.292, 1.571, 0.010, 222.451, 48.511},
{24.264, 75.200, 119.338, -0.300, 1.571, 0.010, 222.451, 49.263},
{25.028, 76.394, 119.335, -0.308, 1.571, 0.010, 222.451, 50.027},
{25.804, 77.587, 119.332, -0.314, 1.571, 0.010, 222.451, 50.803},
{26.592, 78.780, 119.329, -0.319, 1.571, 0.010, 222.451, 51.591},
{27.391, 79.974, 119.325, -0.322, 1.571, 0.010, 222.451, 52.390},
{28.203, 81.167, 119.322, -0.324, 1.571, 0.010, 222.451, 53.202},
{29.027, 82.360, 119.319, -0.325, 1.571, 0.010, 222.450, 54.026},
{29.862, 83.553, 119.316, -0.323, 1.571, 0.010, 222.450, 54.861},
{30.710, 84.746, 119.313, -0.319, 1.571, 0.010, 222.450, 55.709},
{31.569, 85.939, 119.309, -0.314, 1.571, 0.010, 222.450, 56.568},
{32.440, 87.132, 119.306, -0.306, 1.571, 0.010, 222.450, 57.439},
{33.324, 88.325, 119.303, -0.295, 1.571, 0.010, 222.450, 58.322},
{34.219, 89.518, 119.301, -0.282, 1.571, 0.010, 222.450, 59.218},
{35.126, 90.711, 119.298, -0.266, 1.571, 0.010, 222.450, 60.125},
{36.045, 91.904, 119.295, -0.247, 1.571, 0.010, 222.450, 61.044},
{36.976, 93.097, 119.293, -0.225, 1.571, 0.010, 222.450, 61.975},
{37.919, 94.290, 119.291, -0.199, 1.571, 0.010, 222.450, 62.918},
{38.874, 95.483, 119.290, -0.170, 1.571, 0.010, 222.450, 63.873},
{39.840, 96.646, 116.304, -298.519, 1.571, 0.010, 222.450, 64.839},
{40.818, 97.749, 110.336, -596.854, 1.571, 0.010, 222.450, 65.816},
{41.806, 98.793, 104.368, -596.797, 1.571, 0.010, 222.449, 66.804},
{42.803, 99.777, 98.400, -596.737, 1.571, 0.010, 222.449, 67.802},
{43.810, 100.702, 92.434, -596.675, 1.571, 0.010, 222.449, 68.809},
{44.826, 101.566, 86.468, -596.609, 1.571, 0.010, 222.449, 69.825},
{45.850, 102.371, 80.502, -596.542, 1.571, 0.010, 222.449, 70.849},
{46.881, 103.117, 74.537, -596.473, 1.571, 0.010, 222.449, 71.880},
{47.919, 103.802, 68.573, -596.402, 1.571, 0.010, 222.449, 72.918},
{48.963, 104.428, 62.610, -596.331, 1.571, 0.010, 222.449, 73.962},
{50.013, 104.995, 56.648, -596.260, 1.571, 0.010, 222.449, 75.012},
{51.068, 105.502, 50.686, -596.189, 1.571, 0.010, 222.449, 76.067},
{52.128, 105.949, 44.724, -596.118, 1.571, 0.010, 222.449, 77.126},
{53.191, 106.337, 38.764, -596.050, 1.571, 0.010, 222.449, 78.190},
{54.258, 106.665, 32.804, -595.983, 1.571, 0.010, 222.449, 79.257},
{55.327, 106.933, 26.845, -595.918, 1.571, 0.010, 222.449, 80.326},
{56.398, 107.142, 20.886, -595.857, 1.571, 0.010, 222.449, 81.397},
{57.471, 107.291, 14.928, -595.800, 1.571, 0.010, 222.449, 82.470},
{58.545, 107.381, 8.971, -595.747, 1.571, 0.010, 222.449, 83.544},
{59.619, 107.397, 1.575, -739.629, 1.571, 0.010, 222.449, 84.618},
{60.693, 107.339, -5.821, -739.589, 1.571, 0.010, 222.449, 85.691},
{61.765, 107.221, -11.777, -595.624, 1.571, 0.010, 222.449, 86.764},
{62.835, 107.043, -17.733, -595.595, 1.571, 0.010, 222.449, 87.834},
{63.903, 106.807, -23.689, -595.574, 1.571, 0.010, 222.449, 88.902},
{64.968, 106.510, -29.645, -595.560, 1.571, 0.010, 222.450, 89.967},
{66.030, 106.154, -35.600, -595.554, 1.571, 0.010, 222.450, 91.029},
{67.087, 105.739, -41.556, -595.556, 1.571, 0.010, 222.450, 92.086},
{68.140, 105.263, -47.512, -595.567, 1.571, 0.010, 222.450, 93.139},
{69.187, 104.729, -53.467, -595.586, 1.571, 0.010, 222.450, 94.186},
{70.229, 104.145, -58.418, -495.042, 1.571, 0.010, 222.450, 95.227},
{71.267, 103.840, -30.497, 2792.120, 1.571, 0.010, 222.450, 96.266},
{72.305, 103.808, -3.205, 2729.137, 1.572, 0.010, 222.449, 97.304},
{73.344, 103.925, 11.742, 1494.702, 1.573, 0.010, 222.448, 98.343},
{74.386, 104.173, 24.770, 1302.775, 1.576, 0.010, 222.444, 99.385},
{75.431, 104.535, 36.262, 1149.251, 1.579, 0.010, 222.437, 100.430},
{76.481, 105.001, 46.612, 1035.021, 1.584, 0.010, 222.426, 101.480},
{77.537, 105.563, 56.203, 959.028, 1.590, 0.010, 222.409, 102.536},
{78.599, 106.217, 65.391, 918.841, 1.597, 0.010, 222.385, 103.598},
{79.669, 106.962, 74.501, 910.985, 1.606, 0.010, 222.353, 104.667},
{80.747, 107.817, 85.464, 1096.343, 1.616, 0.010, 222.310, 105.744},
{81.835, 108.822, 100.511, 1504.674, 1.628, 0.010, 222.254, 106.831},
{82.935, 110.007, 118.540, 1802.905, 1.642, 0.010, 222.184, 107.929},
{84.049, 111.388, 138.098, 1955.835, 1.658, 0.010, 222.095, 109.039},
{85.179, 112.982, 159.360, 2126.126, 1.677, 0.010, 221.986, 110.164},
{86.327, 114.806, 182.389, 2302.909, 1.697, 0.010, 221.854, 111.304},
{87.496, 116.877, 207.093, 2470.401, 1.721, 0.010, 221.693, 112.462},
{88.688, 119.208, 233.150, 2605.759, 1.747, 0.010, 221.499, 113.638},
{89.906, 121.808, 259.917, 2676.682, 1.776, 0.010, 221.268, 114.834},
{91.153, 124.671, 286.307, 2638.989, 1.809, 0.010, 220.994, 116.050},
{92.431, 127.777, 310.659, 2435.194, 1.845, 0.010, 220.671, 117.286},
{93.741, 131.083, 330.613, 1995.434, 1.884, 0.010, 220.292, 118.541},
{95.086, 134.514, 343.046, 1243.312, 1.928, 0.010, 219.849, 119.811},
{96.466, 137.955, 344.140, 109.370, 1.975, 0.010, 219.337, 121.092},
{97.879, 141.252, 329.685, -1445.465, 2.025, 0.010, 218.750, 122.377},
{99.321, 144.209, 295.708, -3397.776, 2.079, 0.010, 218.082, 123.655},
{100.787, 146.603, 239.420, -5628.790, 2.136, 0.010, 217.332, 124.915},
{102.269, 148.207, 160.346, -7907.349, 2.195, 0.010, 216.501, 126.142},
{103.757, 148.819, 61.252, -9909.403, 2.256, 0.010, 215.595, 127.322},
{105.240, 148.303, -51.603, -11285.541, 2.317, 0.010, 214.621, 128.441},
{106.706, 146.611, -169.233, -11762.944, 2.378, 0.010, 213.594, 129.487},
{108.144, 143.795, -281.631, -11239.806, 2.437, 0.010, 212.526, 130.450},
{109.544, 139.996, -379.865, -9823.405, 2.495, 0.010, 211.434, 131.326},
{110.898, 135.418, -457.768, -7790.292, 2.549, 0.010, 210.331, 132.112},
{112.201, 130.292, -512.678, -5491.015, 2.601, 0.010, 209.232, 132.811},
{113.449, 124.840, -545.163, -3248.503, 2.649, 0.010, 208.146, 133.428},
{114.642, 119.259, -558.078, -1291.523, 2.693, 0.010, 207.084, 133.969},
{115.779, 113.705, -555.441, 263.710, 2.734, 0.010, 206.049, 134.441},
{116.862, 108.290, -541.483, 1395.823, 2.772, 0.010, 205.047, 134.851},
{117.893, 103.090, -520.031, 2145.153, 2.806, 0.010, 204.079, 135.207},
{118.874, 98.147, -494.215, 2581.647, 2.837, 0.010, 203.147, 135.515},
{119.809, 93.483, -466.398, 2781.624, 2.866, 0.010, 202.252, 135.782},
{120.700, 89.101, -438.254, 2814.399, 2.892, 0.010, 201.391, 136.013},
{121.550, 84.992, -410.888, 2736.634, 2.916, 0.010, 200.565, 136.213},
{122.362, 81.142, -384.974, 2591.374, 2.937, 0.010, 199.772, 136.386},
{123.137, 77.534, -360.878, 2409.602, 2.957, 0.010, 199.012, 136.536},
{123.878, 74.146, -338.753, 2212.533, 2.975, 0.010, 198.282, 136.666},
{124.588, 70.960, -318.613, 2014.019, 2.991, 0.010, 197.581, 136.778},
{125.268, 67.956, -300.386, 1822.637, 3.006, 0.010, 196.908, 136.875},
{125.919, 65.116, -283.954, 1643.275, 3.019, 0.010, 196.263, 136.959},
{126.543, 62.425, -269.170, 1478.368, 3.031, 0.010, 195.642, 137.031},
{127.142, 59.866, -255.883, 1328.744, 3.043, 0.010, 195.047, 137.094},
{127.716, 57.427, -243.940, 1194.266, 3.053, 0.010, 194.475, 137.147},
{128.267, 55.095, -233.198, 1074.188, 3.062, 0.010, 193.926, 137.194},
{128.795, 52.859, -223.523, 967.472, 3.070, 0.010, 193.399, 137.234},
{129.303, 50.711, -214.794, 872.931, 3.078, 0.010, 192.893, 137.268},
{129.789, 48.642, -206.900, 789.365, 3.085, 0.010, 192.408, 137.297},
{130.255, 46.645, -199.745, 715.582, 3.091, 0.010, 191.942, 137.322},
{130.703, 44.713, -193.240, 650.492, 3.097, 0.010, 191.495, 137.343},
{131.131, 42.839, -187.309, 593.070, 3.102, 0.010, 191.067, 137.361},
{131.541, 41.021, -181.885, 542.397, 3.107, 0.010, 190.657, 137.376},
{131.934, 39.251, -176.909, 497.644, 3.111, 0.010, 190.265, 137.389},
{132.309, 37.528, -172.328, 458.073, 3.115, 0.010, 189.890, 137.400},
{132.667, 35.847, -168.098, 423.017, 3.118, 0.010, 189.532, 137.409},
{133.009, 34.205, -164.179, 391.897, 3.121, 0.010, 189.190, 137.416},
{133.335, 32.600, -160.537, 364.186, 3.124, 0.010, 188.864, 137.422},
{133.646, 31.029, -157.143, 339.428, 3.126, 0.010, 188.553, 137.428},
{133.941, 29.489, -153.971, 317.198, 3.128, 0.010, 188.259, 137.432},
{134.220, 27.979, -150.999, 297.139, 3.130, 0.010, 187.979, 137.435},
{134.485, 26.497, -148.210, 278.918, 3.132, 0.010, 187.714, 137.438},
{134.736, 25.041, -145.588, 262.238, 3.133, 0.010, 187.463, 137.440},
{134.972, 23.610, -143.119, 246.839, 3.134, 0.010, 187.227, 137.442},
{135.194, 22.202, -140.794, 232.487, 3.135, 0.010, 187.005, 137.444},
{135.402, 20.816, -138.605, 218.967, 3.136, 0.010, 186.797, 137.445},
{135.597, 19.450, -136.544, 206.097, 3.137, 0.010, 186.603, 137.446},
{135.778, 18.104, -134.607, 193.705, 3.138, 0.010, 186.422, 137.447},
{135.945, 16.776, -132.790, 181.651, 3.138, 0.010, 186.254, 137.447},
{136.100, 15.465, -131.092, 169.803, 3.139, 0.010, 186.099, 137.448},
{136.242, 14.170, -129.512, 158.056, 3.139, 0.010, 185.958, 137.448},
{136.371, 12.890, -128.048, 146.316, 3.139, 0.010, 185.829, 137.448},
{136.487, 11.638, -125.233, 281.535, 3.139, 0.010, 185.712, 137.449},
{136.591, 10.442, -119.517, 571.638, 3.140, 0.010, 185.608, 137.449},
{136.685, 9.318, -112.400, 711.706, 3.140, 0.010, 185.515, 137.449},
{136.767, 8.264, -105.453, 694.672, 3.140, 0.010, 185.432, 137.449},
{136.840, 7.277, -98.660, 679.336, 3.140, 0.010, 185.359, 137.449},
{136.904, 6.357, -92.003, 665.624, 3.140, 0.010, 185.296, 137.450},
{136.959, 5.503, -85.469, 653.461, 3.140, 0.010, 185.241, 137.450},
{137.006, 4.712, -79.041, 642.772, 3.140, 0.010, 185.194, 137.450},
{137.046, 3.985, -72.706, 633.479, 3.140, 0.010, 185.154, 137.450},
{137.079, 3.321, -66.451, 625.499, 3.140, 0.010, 185.120, 137.450},
{137.106, 2.718, -60.264, 618.747, 3.140, 0.010, 185.093, 137.450},
{137.128, 2.177, -54.132, 613.132, 3.140, 0.010, 185.072, 137.450},
{137.145, 1.696, -48.047, 608.556, 3.140, 0.010, 185.055, 137.450},
{137.157, 1.276, -41.998, 604.921, 3.140, 0.010, 185.042, 137.450},
{137.167, 0.916, -35.976, 602.123, 3.140, 0.010, 185.033, 137.450},
{137.173, 0.617, -29.976, 600.054, 3.140, 0.010, 185.026, 137.450},
{137.177, 0.377, -23.990, 598.607, 3.140, 0.010, 185.023, 137.450},
{137.179, 0.197, -18.013, 597.670, 3.140, 0.010, 185.021, 137.450},
{137.179, 0.076, -12.042, 597.131, 3.140, 0.010, 185.020, 137.450},
{137.179, 0.015, -6.073, 596.877, 3.140, 0.010, 185.020, 137.450},
{137.179, 0.000, -1.544, 452.852, 3.140, 0.010, 185.020, 137.450}};
#endif