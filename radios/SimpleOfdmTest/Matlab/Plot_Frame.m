close all
clear all

Frame = read_complex_float_single_file('../Output_Data/OfdmFrame', inf);
plot_complex_array(Frame, 'OFDM Frame');
