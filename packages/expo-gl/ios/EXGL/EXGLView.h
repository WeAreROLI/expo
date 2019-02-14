// Copyright 2016-present 650 Industries. All rights reserved.

#import <EXGL-CPP/UEXGL.h>
#import <EXGL/EXGLContext.h>
#import <EXCore/EXModuleRegistry.h>

NS_ASSUME_NONNULL_BEGIN

@interface EXGLView : UIView <EXGLContextDelegate>

- (instancetype)initWithModuleRegistry:(EXModuleRegistry *)moduleRegistry;
- (UEXGLContextId)exglCtxId;

// AR
- (void)setArSessionManager:(id)arSessionManager;
- (void)maybeStopARSession;

@property (nonatomic, copy, nullable) EXDirectEventBlock onSurfaceCreate;
@property (nonatomic, copy, nullable) EXDirectEventBlock onFrame;
@property (nonatomic, copy, nullable) NSNumber preferredFramesPerSecond;

@property (nonatomic, assign) NSNumber *msaaSamples;

// "protected"
@property (nonatomic, strong, nullable) EXGLContext *glContext;
@property (nonatomic, strong, nullable) EAGLContext *uiEaglCtx;

@end

NS_ASSUME_NONNULL_END
