clear, clf

carrierFrequencyHz = 1.5e9;
distReference = 100;
varianceDB = 3;
distBaseToMobileStation = [1:2:31].^2;
txAntennaGainDB = [1 1 0.5];
rxAntennaGainDB = [1 0.5 0.5];
pathLossExp = [2 3 6];

for k = 1:3
    pathLossFreeDB(k, :)  = PathLoss_freeSpace(carrierFrequencyHz, ...
        distBaseToMobileStation, ...
        txAntennaGainDB(k), ...
        rxAntennaGainDB(k));
    pathLossLogDistanceDB(k, :) = PathLoss_LogDistanceOrNormal(carrierFrequencyHz, ...
        distBaseToMobileStation, ...
        distReference, ...
        pathLossExp(k));
    pathLossLogNormalDB(k, :) = PathLoss_LogDistanceOrNormal(carrierFrequencyHz, ...
        distBaseToMobileStation, ...
        distReference, ...
        pathLossExp(1), ...
        varianceDB);
end

figure,
subplot(1,3,1),
semilogx(distBaseToMobileStation, pathLossFreeDB(1,:), 'k-o', ...
    distBaseToMobileStation, pathLossFreeDB(2,:), 'k-^', ...
    distBaseToMobileStation, pathLossFreeDB(3,:), 'k-s'),
grid on,
axis([1 1000 40 110]),
title(['Free Path-loss Model, f_c=', num2str(carrierFrequencyHz/1e6), 'MHz'])
xlabel('Distance(m)'), ylabel('Path Loss (dB)'),
legend('G_t=1, G_r=1', 'G_t=1, G_r=0.5', 'G_t=0.5, G_r=0.5')

subplot(1,3,2),
semilogx(distBaseToMobileStation, pathLossLogDistanceDB(1,:), 'k-o', ...
    distBaseToMobileStation, pathLossLogDistanceDB(2,:), 'k-^', ...
    distBaseToMobileStation, pathLossLogDistanceDB(3,:), 'k-s'),
grid on,
axis([1 1000 40 110]),
title(['Log-Distance Path-loss Model, f_c=', num2str(carrierFrequencyHz/1e6), 'MHz'])
xlabel('Distance(m)'), ylabel('Path Loss (dB)'),
legend('n=2', 'n=3', 'n=6')


subplot(1,3,3),
semilogx(distBaseToMobileStation, pathLossLogNormalDB(1,:), 'k-o', ...
    distBaseToMobileStation, pathLossLogNormalDB(2,:), 'k-^', ...
    distBaseToMobileStation, pathLossLogNormalDB(3,:), 'k-s'),
grid on,
axis([1 1000 40 110]),
title(['Log-Normal Path-loss Model, f_c=', num2str(carrierFrequencyHz/1e6), 'MHz, ', ...
    num2str(varianceDB), ' dB, n=2'])
xlabel('Distance(m)'), ylabel('Path Loss (dB)'),
legend('path1', 'path2', 'path3')