% Log-distance or Log-normal shadowing path model
function pathLossDB = PathLoss_logDistanceOrNormal(carrierFrequencyHz, ...
    distBaseToMobileStation, ...
    distReference, ...
    pathLossExp, ...
    varianceDB)


wavelength = 3e8/carrierFrequencyHz;
% PL(dB) = -20*log10(lambda/(4*pi*d)) + 10*log10(d/d0)
pathLossDB = -20 * log10(wavelength ./ (4*pi*distBaseToMobileStation)) + ...
    10*pathLossExp*log10(distBaseToMobileStation/distReference);

if nargin > 4
    pathLossDB = pathLossDB + varianceDB*randn(size(distBaseToMobileStation));
end




