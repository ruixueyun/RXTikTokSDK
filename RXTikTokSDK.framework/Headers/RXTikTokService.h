//
//  RXTikTokService.h
//  RXTikTokSDK
//
//  Created by 陈汉 on 2023/7/29.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

// 分享类型
typedef NS_ENUM(NSUInteger, RXTTShareType) {
    RXTTShareTypeImage = 0,     // 图片类型
    RXTTShareTypeVideo = 1,     // 视频类型
};

// 在TikTok中的状态
typedef NS_ENUM(NSUInteger, RXTTShareTypeLandedPageType) {
    RXTTShareTypeLandedPageTypeClip = 0,      // 修剪状态
    RXTTShareTypeLandedPageTypeEdit = 1,      // 编辑状态
    RXTTShareTypeLandedPageTypePublish = 2,   // 发布状态
};


@interface RXTikTokService : NSObject

/**
 * 获取SDK实例（单例）
 */
+ (instancetype)sharedSDK;

/**
 * 注册TikTok
 */
- (void)TTRegistWithApplication:(UIApplication *)application
                  launchOptions:(NSDictionary *)launchOptions;

/**
 * 处理跳转参数 openUrl 方式
 */
- (BOOL)TTApplication:(UIApplication *)application
              openURL:(NSURL *)url
              options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;

/**
 * TikTok 分享
 * @param type 分享类型
 * @param landedPageType 在TikTok中的状态
 * @param media 分享资源
 * type是图片类型则为图片资源（UIImage/NSData/URL/LocalPath）
 * type是视频类型则为视频资源
 */
- (void)sendShareWithType:(RXTTShareType)type
           landedPageType:(RXTTShareTypeLandedPageType)landedPageType
                    media:(id)media
                 complete:(void(^)(void(^)(NSDictionary *response, NSDictionary *error)))complete;

@end

NS_ASSUME_NONNULL_END
