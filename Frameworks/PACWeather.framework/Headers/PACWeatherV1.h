/** @module PACWeather.framework *///
//  PACWeatherV1.h
//  Weather
//
//  Copyright © 2016 Panasonic Avionics Corporation. All rights reserved.
//

#import <PACCoreKit/PACCoreKit.h>
#import <PACWeather/PACWeatherV1CurrentWeatherItem.h>
#import <PACWeather/PACWeatherV1WeatherForecast.h>

/**
 This class is responsible for retrieving the current and forecasted weather from the server.
 
 [Download Sample Project](../../samples/PACWeather/SampleWeatherApplication.zip)
 
 ***Example***
 
        ...
        @property (readwrite,nonatomic,strong)  NSArray<PACWeatherV1CurrentWeatherItem*>*   currentWeather;
        ...
 
         -(void)viewDidLoad
        {
            [super viewDidLoad];

            ...
 
            self.weatherService = [PACWeatherV1 initService:nil];
        }
 
         -(IBAction )refreshWeatherInfo:(id )sender
        {
            [self.weatherService sendCurrentWeatherRequestWithQueue:[NSOperationQueue mainQueue] completion:
            ^(
                NSArray<PACWeatherV1CurrentWeatherItem*>*   weather,
                NSError*                                    error
            )
            {
                // Optionally, you may sort the weather array based on ICAO code
                self.currentWeather = [weather sortedArrayUsingComparator:^NSComparisonResult
                (
                    id  obj1,
                    id  obj2
                )
                {
                    NSComparisonResult              result;
                    PACWeatherV1CurrentWeatherItem* firstObject = (PACWeatherV1CurrentWeatherItem* )obj1;
                    PACWeatherV1CurrentWeatherItem* secondObject = (PACWeatherV1CurrentWeatherItem* )obj2;

                    result = [firstObject.ICAOCode compare:secondObject.ICAOCode];

                    return result;
                }];
 
                // Refresh the table view
                [self.tableView reloadData];
            }];
        }
 
 */
@interface PACWeatherV1 : InFlightService


/**
 * @constantgroup PACWeatherV1WeatherIcons
 * Weather icons.
 */
/** The icon is sunny. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconSunny;
/** The icon is haze. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconHaze;
/** The icon is clouds. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconClouds;
/** The icon is fog. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconFog;
/** The icon is dust. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconDust;
/** The icon is smoke. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconSmoke;
/** The icon is light rain. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconLightRain;
/** The icon is rain. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconRain;
/** The icon is flood. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconFlood;
/** The icon is storm. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconStorm;
/** The icon is icy. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconIcy;
/** The icon is snow. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconSnow;
/** The icon is flurries. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconFlurries;
/** The icon is hail. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconHail;
/** The icon is tornado. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconTornado;
/** The icon is hurricane. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconHurricane;
/** The icon is sleet. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconSleet;
/** The icon is blizzard. */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherIconBlizzard;

/**
 * The values for weather condition codes.
 * @owner PACWeatherV1
 */
typedef enum PACWeatherV1WeatherConditionCode
{
    /** The weather condition is No Report */
    PACWeatherV1WeatherConditionCodeNoReport					= 1,
    
    /** The weather condition is Sunny */
    PACWeatherV1WeatherConditionCodeSunny						= 1001,
    /** The weather condition is Clear */
    PACWeatherV1WeatherConditionCodeClear						= 1002,
    /** The weather condition is Mostly Sunny */
    PACWeatherV1WeatherConditionCodeMostlySunny					= 1003,
    /** The weather condition is Mostly Clear */
    PACWeatherV1WeatherConditionCodeMostlyClear					= 1004,
    /** The weather condition is More Sun Than Clouds */
    PACWeatherV1WeatherConditionCodeMoreSunThanClouds			= 1005,
    /** The weather condition is Partly Sunny */
    PACWeatherV1WeatherConditionCodePartlySunny					= 1006,
    /** The weather condition is Breaks Of Sun Late */
    PACWeatherV1WeatherConditionCodeBreaksOfSunLate				= 1007,
    
    /** The weather condition is Hazy Sunshine */
    PACWeatherV1WeatherConditionCodeHazySunshine				= 2001,
    /** The weather condition is Haze */
    PACWeatherV1WeatherConditionCodeHaze						= 2002,
    /** The weather condition is Low Level Haze */
    PACWeatherV1WeatherConditionCodeLowLevelHaze				= 2003,
    
    /** The weather condition is Passing Clouds */
    PACWeatherV1WeatherConditionCodePassingClouds				= 3001,
    /** The weather condition is Scattered Clouds */
    PACWeatherV1WeatherConditionCodeScatteredClouds				= 3002,
    /** The weather condition is Partly Cloudy */
    PACWeatherV1WeatherConditionCodePartlyCloudy				= 3003,
    /** The weather condition is A Mixture Of Sun And Clouds */
    PACWeatherV1WeatherConditionCodeAMixtureOfSunAndClouds		= 3004,
    /** The weather condition is High Level Clouds */
    PACWeatherV1WeatherConditionCodeHighLevelClouds				= 3005,
    /** The weather condition is More Clouds Than Sun */
    PACWeatherV1WeatherConditionCodeMoreCloudsThanSun			= 3006,
    /** The weather condition is Broken Clouds */
    PACWeatherV1WeatherConditionCodeBrokenClouds				= 3007,
    /** The weather condition is Mostly Cloudy */
    PACWeatherV1WeatherConditionCodeMostlyCloudy				= 3008,
    /** The weather condition is Cloudy */
    PACWeatherV1WeatherConditionCodeCloudy						= 3009,
    /** The weather condition is Overcast */
    PACWeatherV1WeatherConditionCodeOvercast					= 3010,
    /** The weather condition is Low Clouds */
    PACWeatherV1WeatherConditionCodeLowClouds					= 3011,
    /** The weather condition is Increasing Cloudiness */
    PACWeatherV1WeatherConditionCodeIncreasingCloudiness		= 3012,
    /** The weather condition is Decreasing Cloudiness */
    PACWeatherV1WeatherConditionCodeDecreasingCloudiness		= 3013,
    /** The weather condition is Clearing Skies */
    PACWeatherV1WeatherConditionCodeClearingSkies				= 3014,
    /** The weather condition is Afternoon Clouds */
    PACWeatherV1WeatherConditionCodeAfternoonClouds				= 3015,
    /** The weather condition is Morning Clouds */
    PACWeatherV1WeatherConditionCodeMorningClouds				= 3016,
    
    /** The weather condition is Light Fog */
    PACWeatherV1WeatherConditionCodeLightFog					= 4001,
    /** The weather condition is Fog */
    PACWeatherV1WeatherConditionCodeFog							= 4002,
    /** The weather condition is Dense Fog */
    PACWeatherV1WeatherConditionCodeDenseFog					= 4003,
    /** The weather condition is Ice Fog */
    PACWeatherV1WeatherConditionCodeIceFog						= 4004,
    /** The weather condition is Early Fog Followed By Sunny Sky */
    PACWeatherV1WeatherConditionCodeEarlyFogFollowedBySunnySky	= 4005,
    
    /** The weather condition is Sandstorm */
    PACWeatherV1WeatherConditionCodeSandstorm					= 5001,
    /** The weather condition is Duststorm */
    PACWeatherV1WeatherConditionCodeDuststorm					= 5002,
    
    /** The weather condition is Smoke */
    PACWeatherV1WeatherConditionCodeSmoke						= 6001,
    
    /** The weather condition is Drizzle */
    PACWeatherV1WeatherConditionCodeDrizzle						= 7001,
    /** The weather condition is Sprinkles */
    PACWeatherV1WeatherConditionCodeSprinkles					= 7002,
    /** The weather condition is Scattered Showers */
    PACWeatherV1WeatherConditionCodeScatteredShowers			= 7003,
    /** The weather condition is A Few Showers */
    PACWeatherV1WeatherConditionCodeAFewShowers					= 7004,
    /** The weather condition is Light Showers */
    PACWeatherV1WeatherConditionCodeLightShowers				= 7005,
    /** The weather condition is Passing Showers */
    PACWeatherV1WeatherConditionCodePassingShowers				= 7006,
    /** The weather condition is Numerous Showers */
    PACWeatherV1WeatherConditionCodeNumerousShowers				= 7007,
    /** The weather condition is Showery */
    PACWeatherV1WeatherConditionCodeShowery						= 7008,
    /** The weather condition is Light Freezing Rain */
    PACWeatherV1WeatherConditionCodeLightFreezingRain			= 7009,
    /** The weather condition is Sprinkles Early */
    PACWeatherV1WeatherConditionCodeSprinklesEarly				= 7010,
    /** The weather condition is Showers Early */
    PACWeatherV1WeatherConditionCodeShowersEarly				= 7011,
    /** The weather condition is Light Rain Early */
    PACWeatherV1WeatherConditionCodeLightRainEarly				= 7012,
    /** The weather condition is Sprinkles Late */
    PACWeatherV1WeatherConditionCodeSprinklesLate				= 7013,
    /** The weather condition is Showers Late */
    PACWeatherV1WeatherConditionCodeShowersLate					= 7014,
    /** The weather condition is Light Rain Late */
    PACWeatherV1WeatherConditionCodeLightRainLate				= 7015,
    /** The weather condition is Light Rain */
    PACWeatherV1WeatherConditionCodeLightRain					= 7016,
    
    /** The weather condition is Rain Showers */
    PACWeatherV1WeatherConditionCodeRainShowers					= 8001,
    /** The weather condition is Rain */
    PACWeatherV1WeatherConditionCodeRain						= 8002,
    /** The weather condition is Heavy Rain */
    PACWeatherV1WeatherConditionCodeHeavyRain					= 8003,
    /** The weather condition is Lots Of Rain */
    PACWeatherV1WeatherConditionCodeLotsOfRain					= 8004,
    /** The weather condition is Tons Of Rain */
    PACWeatherV1WeatherConditionCodeTonsOfRain					= 8005,
    /** The weather condition is Light Mixture Of Precip */
    PACWeatherV1WeatherConditionCodeLightMixtureOfPrecip		= 8006,
    /** The weather condition is Mixture Of Precip */
    PACWeatherV1WeatherConditionCodeMixtureOfPrecip				= 8007,
    /** The weather condition is Heavy Mixture Of Precip */
    PACWeatherV1WeatherConditionCodeHeavyMixtureOfPrecip		= 8008,
    /** The weather condition is Rain Early */
    PACWeatherV1WeatherConditionCodeRainEarly					= 8009,
    /** The weather condition is Heavy Rain Early */
    PACWeatherV1WeatherConditionCodeHeavyRainEarly				= 8010,
    /** The weather condition is Rain Late */
    PACWeatherV1WeatherConditionCodeRainLate					= 8011,
    /** The weather condition is Heavy Rain Late */
    PACWeatherV1WeatherConditionCodeHeavyRainLate				= 8012,
    
    /** The weather condition is Flash Floods */
    PACWeatherV1WeatherConditionCodeFlashFloods					= 9001,
    
    /** The weather condition is Widely Scattered Tstorms */
    PACWeatherV1WeatherConditionCodeWidelyScatteredTstorms		= 10001,
    /** The weather condition is Isolated Tstorms */
    PACWeatherV1WeatherConditionCodeIsolatedTstorms				= 10002,
    /** The weather condition is A Few Thunderstorms */
    PACWeatherV1WeatherConditionCodeAFewThunderstorms			= 10003,
    /** The weather condition is Thundershowers */
    PACWeatherV1WeatherConditionCodeThundershowers				= 10004,
    /** The weather condition is Thunderstorms */
    PACWeatherV1WeatherConditionCodeThunderstorms				= 10005,
    /** The weather condition is Strong Thunderstorms */
    PACWeatherV1WeatherConditionCodeStrongThunderstorms			= 10006,
    /** The weather condition is Severe Thunderstorms */
    PACWeatherV1WeatherConditionCodeSevereThunderstorms			= 10007,
    /** The weather condition is Tropical Storm */
    PACWeatherV1WeatherConditionCodeTropicalStorm				= 10008,
    /** The weather condition is Tstorms Early */
    PACWeatherV1WeatherConditionCodeTstormsEarly				= 10009,
    /** The weather condition is Isolated Tstorms Late */
    PACWeatherV1WeatherConditionCodeIsolatedTstormsLate			= 10010,
    /** The weather condition is Scattered Tstorms Late */
    PACWeatherV1WeatherConditionCodeScatteredTstormsLate		= 10011,
    /** The weather condition is Tstorms Late */
    PACWeatherV1WeatherConditionCodeTstormsLate					= 10012,
    
    /** The weather condition is Icy Mix */
    PACWeatherV1WeatherConditionCodeIcyMix						= 11001,
    /** The weather condition is Snow Changing To An Icy Mix */
    PACWeatherV1WeatherConditionCodeSnowChangingToAnIcyMix		= 11002,
    /** The weather condition is An Icy Mix Changing To Snow */
    PACWeatherV1WeatherConditionCodeAnIcyMixChangingToSnow		= 11003,
    /** The weather condition is An Icy Mix Changing To Rain */
    PACWeatherV1WeatherConditionCodeAnIcyMixChangingToRain		= 11004,
    /** The weather condition is Rain Changing To An Icy Mix */
    PACWeatherV1WeatherConditionCodeRainChangingToAnIcyMix		= 11005,
    /** The weather condition is Light Icy Mix Early */
    PACWeatherV1WeatherConditionCodeLightIcyMixEarly			= 11006,
    /** The weather condition is Icy Mix Early */
    PACWeatherV1WeatherConditionCodeIcyMixEarly					= 11007,
    /** The weather condition is Icy Mix_Late */
    PACWeatherV1WeatherConditionCodeIcyMix_Late					= 11008,
    
    /** The weather condition is Freezing Rain */
    PACWeatherV1WeatherConditionCodeFreezingRain				= 12001,
    /** The weather condition is Snow Changing To Rain */
    PACWeatherV1WeatherConditionCodeSnowChangingToRain			= 12002,
    /** The weather condition is Rain Changing To Snow */
    PACWeatherV1WeatherConditionCodeRainChangingToSnow			= 12003,
    /** The weather condition is Light Snow Showers */
    PACWeatherV1WeatherConditionCodeLightSnowShowers			= 12004,
    /** The weather condition is Snow Showers */
    PACWeatherV1WeatherConditionCodeSnowShowers					= 12005,
    /** The weather condition is Light Snow */
    PACWeatherV1WeatherConditionCodeLightSnow					= 12006,
    /** The weather condition is Snow */
    PACWeatherV1WeatherConditionCodeSnow						= 12007,
    /** The weather condition is Moderate Snow */
    PACWeatherV1WeatherConditionCodeModerateSnow				= 12008,
    /** The weather condition is Heavy Snow */
    PACWeatherV1WeatherConditionCodeHeavySnow					= 12009,
    /** The weather condition is Snowstorm */
    PACWeatherV1WeatherConditionCodeSnowstorm					= 12010,
    /** The weather condition is Snow Showers Early */
    PACWeatherV1WeatherConditionCodeSnowShowersEarly			= 12011,
    /** The weather condition is Light Snow Early */
    PACWeatherV1WeatherConditionCodeLightSnowEarly				= 12012,
    /** The weather condition is Snow Early */
    PACWeatherV1WeatherConditionCodeSnowEarly					= 12013,
    /** The weather condition is Heavy Snow Early */
    PACWeatherV1WeatherConditionCodeHeavySnowEarly				= 12014,
    /** The weather condition is Snow Showers Late */
    PACWeatherV1WeatherConditionCodeSnowShowersLate				= 12015,
    /** The weather condition is Light Snow Late */
    PACWeatherV1WeatherConditionCodeLightSnowLate				= 12016,
    /** The weather condition is Snow Late */
    PACWeatherV1WeatherConditionCodeSnowLate					= 12017,
    /** The weather condition is Heavy Snow Late */
    PACWeatherV1WeatherConditionCodeHeavySnowLate				= 12018,
    /** The weather condition is Light Icy Mix Late */
    PACWeatherV1WeatherConditionCodeLightIcyMixLate				= 12019,
    
    /** The weather condition is Scattered Flurries */
    PACWeatherV1WeatherConditionCodeScatteredFlurries			= 13001,
    /** The weather condition is Snow Flurries */
    PACWeatherV1WeatherConditionCodeSnowFlurries				= 13002,
    /** The weather condition is Flurries Early */
    PACWeatherV1WeatherConditionCodeFlurriesEarly				= 13003,
    /** The weather condition is Flurries Late */
    PACWeatherV1WeatherConditionCodeFlurriesLate				= 13004,
    
    /** The weather condition is Hail */
    PACWeatherV1WeatherConditionCodeHail						= 14001,
    
    /** The weather condition is Tornado */
    PACWeatherV1WeatherConditionCodeTornado						= 15001,
    
    /** The weather condition is Hurricane */
    PACWeatherV1WeatherConditionCodeHurricane					= 16001,
    
    /** The weather condition is Sleet */
    PACWeatherV1WeatherConditionCodeSleet						= 17001,
    
    /** The weather condition is Blizzard */
    PACWeatherV1WeatherConditionCodeBlizzard					= 18001,
}
PACWeatherV1WeatherConditionCode;

/**
 * @constantgroup PACWeatherV1WeatherConditions
 * The values for weather conditions.
 * @deprecated Please use PACWeatherV1WeatherConditionCode enum instead.
 */
/** The weather condition is Sunny */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSunny;
/** The weather condition is Clear */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionClear;
/** The weather condition is Most Sunny */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionMostSunny;
/** The weather condition is Mostly Clear */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionMostlyClear;
/** The weather condition is More Sun Than Clouds */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionMoreSunThanClouds;
/** The weather condition is Partly Sunny */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionPartlySunny;
/** The weather condition is Beaks Of Sun Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionBeaksOfSunLate;
/** The weather condition is Hazy Sunshine */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionHazySunshine;
/** The weather condition is Haze */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionHaze;
/** The weather condition is Low Level Haze */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLowLevelHaze;
/** The weather condition is Passing Clouds */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionPassingClouds;
/** The weather condition is Scattered Clouds */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionScatteredClouds;
/** The weather condition is Partly Cloudy */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionPartlyCloudy;
/** The weather condition is A Mixture Of Sun And Clounds */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionAMixtureOfSunAndClounds;
/** The weather condition is High Level Clouds */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionHighLevelClouds;
/** The weather condition is More Clounds Than Sun */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionMoreCloundsThanSun;
/** The weather condition is Broken Clouds */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionBrokenClouds;
/** The weather condition is Mostly Cloudy */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionMostlyCloudy;
/** The weather condition is Cloudy */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionCloudy;
/** The weather condition is Overcast */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionOvercast;
/** The weather condition is Low Clouds */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLowClouds;
/** The weather condition is Increasing Cloudiness */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionIncreasingCloudiness;
/** The weather condition is Decreasing Cloudiness */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionDecreasingCloudiness;
/** The weather condition is Clearing Skies */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionClearingSkies;
/** The weather condition is Afternoon Clouds */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionAfternoonClouds;
/** The weather condition is Morning Clouds */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionMorningClouds;
/** The weather condition is Light Fog */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLightFog;
/** The weather condition is Fog */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionFog;
/** The weather condition is Dense Fog */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionDenseFog;
/** The weather condition is Ice Fog */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionIceFog;
/** The weather condition is Early Fog Followed By Sunny Skies */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionEarlyFogFollowedBySunnySkies;
/** The weather condition is Sandstorm */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSandstorm;
/** The weather condition is Duststorm */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionDuststorm;
/** The weather condition is Smoke */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSmoke;
/** The weather condition is Drizzle */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionDrizzle;
/** The weather condition is Sprinkles */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSprinkles;
/** The weather condition is Scattered Showers */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionScatteredShowers;
/** The weather condition is A Few Showers */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionAFewShowers;
/** The weather condition is Light Showers */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLightShowers;
/** The weather condition is Passing Showers */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionPassingShowers;
/** The weather condition is Numerous Showers */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionNumerousShowers;
/** The weather condition is Showery */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionShowery;
/** The weather condition is Light Freezing Rain */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLightFreezingRain;
/** The weather condition is Sprinkles Early */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSprinklesEarly;
/** The weather condition is Showers Early */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionShowersEarly;
/** The weather condition is Light Rain Early */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLightRainEarly;
/** The weather condition is Sprinkles Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSprinklesLate;
/** The weather condition is Showers Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionShowersLate;
/** The weather condition is Light Rain Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLightRainLate;
/** The weather condition is Light Rain */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLightRain;
/** The weather condition is Rain Showers */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionRainShowers;
/** The weather condition is Rain */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionRain;
/** The weather condition is Heavy Rain */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionHeavyRain;
/** The weather condition is Lots Of Rain */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLotsOfRain;
/** The weather condition is Tons Of Rain */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionTonsOfRain;
/** The weather condition is Light Mixture Of Precip */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLightMixtureOfPrecip;
/** The weather condition is Mixture If Precip */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionMixtureIfPrecip;
/** The weather condition is Heavy Mixture Of Precip */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionHeavyMixtureOfPrecip;
/** The weather condition is Rain Early */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionRainEarly;
/** The weather condition is Heavy Rain Early */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionHeavyRainEarly;
/** The weather condition is Rain Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionRainLate;
/** The weather condition is Heavy Rain Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionHeavyRainLate;
/** The weather condition is Flash Floods */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionFlashFloods;
/** The weather condition is Widely Scattered Thunderstorms */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionWidelyScatteredThunderstorms;
/** The weather condition is Isolated Thunderstorms */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionIsolatedThunderstorms;
/** The weather condition is A Few Thunderstorms */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionAFewThunderstorms;
/** The weather condition is Thundershowers */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionThundershowers;
/** The weather condition is Thunderstorms */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionThunderstorms;
/** The weather condition is Strong Thunderstorms */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionStrongThunderstorms;
/** The weather condition is Severe Thunderstorms */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSevereThunderstorms;
/** The weather condition is Tropical Storm */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionTropicalStorm;
/** The weather condition is Thunderstorms Early */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionThunderstormsEarly;
/** The weather condition is Isolated Thunderstorms Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionIsolatedThunderstormsLate;
/** The weather condition is Scattered Thunderstorms Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionScatteredThunderstormsLate;
/** The weather condition is Thunderstorms Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionThunderstormsLate;
/** The weather condition is Icy Mix */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionIcyMix;
/** The weather condition is Snow Chaning To An Icy Mix */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSnowChaningToAnIcyMix;
/** The weather condition is An Icy Mix Changing To Snow */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionAnIcyMixChangingToSnow;
/** The weather condition is An Icy Mix Changing To Rain */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionAnIcyMixChangingToRain;
/** The weather condition is Rain Changing To An Icy Mix */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionRainChangingToAnIcyMix;
/** The weather condition is Light Icy Mix Early */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLightIcyMixEarly;
/** The weather condition is Icy Mix Early */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionIcyMixEarly;
/** The weather condition is Icy Mix Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionIcyMixLate;
/** The weather condition is Freezing Rain */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionFreezingRain;
/** The weather condition is Snow Changing To Rain */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSnowChangingToRain;
/** The weather condition is Rain Changing To Snow */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionRainChangingToSnow;
/** The weather condition is Light Snow Showers */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLightSnowShowers;
/** The weather condition is Snow Showers */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSnowShowers;
/** The weather condition is Light Snow */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLightSnow;
/** The weather condition is Snow */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSnow;
/** The weather condition is Moderate Snow */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionModerateSnow;
/** The weather condition is Heavy Snow */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionHeavySnow;
/** The weather condition is Snow Storm */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSnowStorm;
/** The weather condition is Snow Showers Early */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSnowShowersEarly;
/** The weather condition is Light Snow Early */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLightSnowEarly;
/** The weather condition is Snow Early */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSnowEarly;
/** The weather condition is Heavy Snow Early */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionHeavySnowEarly;
/** The weather condition is Snow Showers Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSnowShowersLate;
/** The weather condition is Light Snow Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLightSnowLate;
/** The weather condition is Snow Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSnowLate;
/** The weather condition is Heavy Snow Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionHeavySnowLate;
/** The weather condition is Light Icy Mix Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionLightIcyMixLate;
/** The weather condition is Scattered Flurries */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionScatteredFlurries;
/** The weather condition is Snow Flurries */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSnowFlurries;
/** The weather condition is Flurries Early */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionFlurriesEarly;
/** The weather condition is Flurries Late */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionFlurriesLate;
/** The weather condition is Hail */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionHail;
/** The weather condition is Tornado */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionTornado;
/** The weather condition is Hurricane */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionHurricane;
/** The weather condition is Sleet */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionSleet;
/** The weather condition is Blizzard */
FOUNDATION_EXPORT NSString* _Nonnull const PACWeatherV1WeatherConditionBlizzard;



/**
 * @constantgroup PACWeatherErrorDomains
 * The error domains associated to the PACWeatherV1 class.
 */

/**
 * The generic error associated with the PACWeatherV1 class.
 */
FOUNDATION_EXPORT NSString * _Nonnull const PACWeatherErrorDomain;


/**
 * The weather request error codes.
 *
 * @owner PACWeatherV1
 */
typedef enum {
    /** The request has failed due to an unknown error. */
    PACWeatherErrorUnknown = 1000,
    /** The request has missing or incorrect parameters. */
    PACWeatherErrorBadRequest = 1001,
    /** The request has failed due to the unavailability of the service. */
    PACWeatherErrorServiceNotFound = 1002,
    /** The request has failed due to an unexpected internal error. */
    PACWeatherErrorInternalError = 1003,
    /** The request has failed due to an unexpected response from the server. */
    PACWeatherErrorBadResponse = 1004,
    /** The request has failed due to a network connection error. */
    PACWeatherErrorConnectionError = 1005
}PACWeatherErrorCode;

/**
 The completion block that is called by the sendCurrentWeatherRequestWithQueue:completion: function.
 @param weather Array of weather objects. Please refer to PACWeatherV1CurrentWeatherItem for more information.
 @param error Response error due to an error occurring while retreiving data.
 */
typedef void (^PACWeatherV1CurrentWeatherCompletionBlock)(NSArray<PACWeatherV1CurrentWeatherItem *> * _Nullable weather, NSError * _Nullable error);

/**
 The completion block that is called by sendWeatherForecastRequestWithICAO:queue:completion: function.
 @param forecast Weather forecast object. Please refer to PACWeatherV1WeatherForecast for more information.
 @param error Response error due to an error occurring while retreiving data.
 */
typedef void (^PACWeatherV1WeatherForecastCompletionBlock)(PACWeatherV1WeatherForecast * _Nullable forecast, NSError * _Nullable error);

/**
 * Initialize a request for getting the current weather for all configured regions.
 *
 * @param queue Queue in which the is completion block called.
 * @param completionHandler Completion block that will be executed upon completion of the request or error. Please refer to PACWeatherV1CurrentWeatherCompletionBlock for more information.
 */
- (void)sendCurrentWeatherRequestWithQueue:(NSOperationQueue * _Nonnull)queue
                                completion:(PACWeatherV1CurrentWeatherCompletionBlock _Nonnull)completionHandler;

/**
 * Initialize a request for getting the current and forecasted weather for a specific ICAO airport code.
 *
 * @param ICAOCode Unique 4-letter ICAO airport code.
 * @param queue Queue in which the completion block is called.
 * @param completionHandler Completion block that will be executed upon completion of the request or error. Please refer to PACWeatherV1WeatherForecastCompletionBlock for more information.
 */
- (void)sendWeatherForecastRequestWithICAO:(NSString * _Nonnull)ICAOCode
                                     queue:(NSOperationQueue * _Nonnull)queue
                                completion:(PACWeatherV1WeatherForecastCompletionBlock _Nonnull)completionHandler;

@end
